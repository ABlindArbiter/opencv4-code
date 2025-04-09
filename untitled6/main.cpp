#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int main()
{
    cv::Mat img = cv::imread("1.jpg");
    if (img.empty())
    {
        std::cout << "名称错误" << std::endl;
        return -1;
    }
    cv::Mat gray, HSV, YUV, Lab, img32;
    img.convertTo(img32, CV_32F, 1.0 / 255);

    cv::cvtColor(img32, HSV, cv::COLOR_BGR2HSV);
    cv::cvtColor(img32, YUV, cv::COLOR_BGR2YUV);
    cv::cvtColor(img32, Lab, cv::COLOR_BGR2Lab);
    cv::cvtColor(img32, gray, cv::COLOR_BGR2GRAY);

    cv::namedWindow("原图", cv::WINDOW_FREERATIO);
    cv::namedWindow("HSV", cv::WINDOW_FREERATIO);
    cv::namedWindow("YUV", cv::WINDOW_FREERATIO);
    cv::namedWindow("Lab", cv::WINDOW_FREERATIO);
    cv::namedWindow("gray", cv::WINDOW_FREERATIO);

    cv::imshow("原图", img32);
    cv::imshow("HSV", img32);
    cv::imshow("YUV", YUV);
    cv::imshow("Lab", Lab);
    cv::imshow("gray", gray);

    cv::waitKey(0);

    return 0;
}
