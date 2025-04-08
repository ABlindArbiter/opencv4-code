#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    float a[12] = {1, 2, 3.3, 4, 5, 9, 5, 7, 8.2, 9, 10, 2};
    float b[12] = {1, 2.2, 3, 1, 3, 10, 6, 7, 8, 9.3, 10, 1};
    cv::Mat imga = cv::Mat(3, 4, CV_32FC1, a);
    cv::Mat imgb = cv::Mat(3, 4, CV_32FC1, b);
    cv::Mat imgas = cv::Mat(2, 3, CV_32FC2, a);
    cv::Mat imgbs = cv::Mat(2, 3, CV_32FC2, b);

    cv::Mat myMax, myMin;
    max(imga, imgb, myMax);
    min(imga, imgb, myMin);

    cv::Mat myMaxs, myMins;
    max(imgas, imgbs, myMaxs);
    min(imgas, imgbs, myMins);

    std::cout << myMax << std::endl << std::endl << myMin << std::endl << std::endl
              << myMaxs << std::endl << std::endl << myMins  << std::endl << std::endl;

    cv::Mat img0 = cv::imread("1.jpg");
    cv::Mat img1 = cv::imread("2.jpg");
    cv::Mat comMin, comMax;
    if (img0.size() == img1.size() && img0.channels() == img1.channels())
    {
        max(img0, img1, comMax);
        min(img0, img1, comMin);
        cv::imshow("comMax", comMax);
        cv::imshow("comMin", comMin);/**/

        cv::Mat src1 = cv::Mat::zeros(cv::Size(512,512), CV_8UC3);//
        cv::Rect rect(100, 100, 300, 300);
        src1(rect) = cv::Scalar(255, 255, 255);
        cv::Mat comsrc1, comsrc2;
        min(img0, src1, comsrc1);
        imshow("comsrc1", comsrc1);

        cv::Mat img0G, img1G, comMinG, comMaxG;
        cv::cvtColor(img0, img0G, cv::COLOR_BGR2GRAY);
        cv::cvtColor(img1, img1G, cv::COLOR_BGR2GRAY);
        max(img0G, img1G, comMax);
        min(img0G, img1G, comMin);
        imshow("comMax", comMax);
        imshow("comMin", comMax);
    }
    else
    {
        std::cerr << "图像尺寸或通道数不一致，无法进行运算" << std::endl;
    }


    cv::waitKey(0);

    return 0;
}
