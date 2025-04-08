#include <opencv2/opencv.hpp>

void drawHist(cv::Mat &hist, int type, std::string name)//归一化并给制直方图函数
{
    int hist_w = 512;
    int hist_h = 400;
    int width = 2;
    cv::Mat histImage = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
    normalize (hist, hist, 255, 0, type, -1, cv::Mat());
    cv::namedWindow(name, cv::WINDOW_NORMAL);
    cv::imshow(name, hist);
}

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat sub_img = cv::imread("2.jpeg");
    cv::Mat img_HSV, sub_HSV, hist, hist2;
    cv::imshow("img", img);
    cv::imshow("sub_img", sub_img);
    //转成HSV空间，提取s、v两个通道
    cvtColor(img, img_HSV, cv::COLOR_BGR2HSV);
    cvtColor(sub_img, sub_HSV, cv::COLOR_BGR2HSV);
    int h_bins = 32;
    int s_bins =32;
    int histSize[] = {h_bins, s_bins};
    //H通道值的范围为0-179)
    float h_ranges[] = {0, 180};
    //s通道值的范围为0-255
    float s_ranges[] = {0, 256};
    const float* ranges[] = {h_ranges, s_ranges};//每个通道的范围
    int channels[] = {0, 1};//统计的通道索引
    //绘制H-S 二维直方图
    calcHist(&sub_HSV, 1, channels, cv::Mat(), hist, 2, histSize, ranges, true, false);
    drawHist(hist, cv::NORM_INF, "hist");//直方图归一化并绘制直方图
    cv::Mat backproj;
    calcBackProject(&img_HSV, 1, channels, hist, backproj, ranges, 1.0);//图像直方图反向投影
    cv::imshow("反向投影后结果", backproj);

    cv::waitKey(0);

    return 0;
}
