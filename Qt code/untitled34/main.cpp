#include <opencv2/opencv.hpp>

void drawHist(cv::Mat &hist, int type, std::string name)
{
    int hist_w = 512;
    int hist_h = 400;
    int width = 2;
    cv::Mat histImage = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
    cv::normalize(hist, hist, 1, 0, type, -1, cv::Mat());
    for(int i = 1; i  <= hist.rows; i++)
    {
        rectangle(histImage, cv::Point(width*(i - 1), hist_h - 1),
                  cv::Point(width*i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
                  cv::Scalar(255, 255, 255), -1);
    }
    cv::imshow(name, histImage);
}

int main()
{
    cv::Mat img = cv::imread("4.png");
    cv::Mat gray, hist, hist2;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::Mat equalImg;
    cv::equalizeHist(gray, equalImg);//均衡化
    const int channels[1] = {0};
    float inRangles[2] = {0, 255};
    const float* rangles[1] = {inRangles};
    const int bins[1] = {256};
    calcHist(&gray, 1, channels, cv::Mat(), hist, 1, bins, rangles);
    calcHist(&equalImg, 1, channels, cv::Mat(), hist2, 1, bins, rangles);
    drawHist(hist, cv::NORM_INF, "hist");
    drawHist(hist2, cv::NORM_INF, "hist2");
    cv::imshow("gray", gray);
    cv::imshow("均衡化图像", equalImg);

    cv::waitKey (0);
    return 0;
}
