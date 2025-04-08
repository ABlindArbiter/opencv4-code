#include <opencv2/opencv.hpp>

int main()
{//7.80,,8.200,,9.80,,10.150//
    cv::Mat img = cv::imread("10.png");
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    //cv::imshow("gray", gray);

    int threshold_value = 150;
    cv::Mat thresh_tozero;
    double ret;
    ret = cv::threshold(gray, thresh_tozero, threshold_value, 225, cv::THRESH_TOZERO);
    //cv::imshow("THRESH_TOZERO", thresh_tozero);

    cv::Mat thresh_tozero1;
    cv::cvtColor(thresh_tozero, thresh_tozero1, cv::COLOR_GRAY2BGR);

    cv::Point pt1(471, 351);
    cv::Point pt2(535, 412);
    cv::Scalar color(0, 0, 255);
    int thickness = 2;
    cv::rectangle(thresh_tozero1, pt1, pt2, color, thickness);
    cv::rectangle(img, pt1, pt2, color, thickness);
    cv::imshow("THRESH_TOZERO1", thresh_tozero1);
    cv::imshow("img", img);

    cv::waitKey(0);

    return 0;
}
