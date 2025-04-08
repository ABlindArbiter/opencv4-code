#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Mat hist;
    const int channels[1] = {0};//通道索引
    float inRanges[2] = {0, 255};
    const float* ranges[1] = {inRanges};//灰度值范围
    const int bins[1] = {256};//灰度值最大值
    calcHist(&gray, 1, channels, cv::Mat(), hist, 1, bins, ranges);

    int hist_w = 512;
    int hist_h = 400;
    int width = 2;
    cv::Mat histImage = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
    for(int i = 1; i  <= hist.rows; i++)
    {
        rectangle(histImage, cv::Point(width*(i - 1), hist_h - 1),
            cv::Point(width*i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
                  cv::Scalar(255, 255, 255), -1);
    }
    cv::namedWindow("histImage", cv::WINDOW_FREERATIO);
    cv::imshow("histImage", histImage);
    cv::imshow("gray", gray);

    cv::waitKey(0);

    return 0;
}
//直方图的x，y各代表什么？
