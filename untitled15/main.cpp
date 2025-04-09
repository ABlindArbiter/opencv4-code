#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat matArray[] = {cv::Mat(1, 2, CV_32FC1, cv::Scalar(0)),
                          cv::Mat(1, 2, CV_32FC1, cv::Scalar(1))};
    cv::Mat vout, hout;
    cv::vconcat(matArray, 2, vout);
    cv::hconcat(matArray, 2, hout);
    std::cout << "竖" << std::endl << vout <<std::endl;
    std::cout << "横" << std::endl << hout <<std::endl;

    cv::Mat A = (cv::Mat_<float>(2, 2) << 1, 7, 2, 8);
    cv::Mat B = (cv::Mat_<float>(2, 2) << 4, 10, 5, 11);
    cv::Mat vC, hC;
    cv::vconcat(A, B, vC);
    cv::hconcat(A, B, hC);
    std::cout << "多竖" << std::endl << vC <<std::endl;
    std::cout << "多横" << std::endl << hC <<std::endl;

    cv::Mat img00 = cv::imread("4.png");
    cv::Mat img01 = cv::imread("4.png");
    cv::Mat img10 = cv::imread("4.png");
    cv::Mat img11 = cv::imread("4.png");
    /*imshow("img00", img00);
    imshow("img01", img01);
    imshow("img10", img10);
    imshow("img11", img11);*/

    cv::Mat img, img0, img1;
    cv::hconcat(img00, img01, img0);
    cv::hconcat(img10, img11, img1);
    cv::vconcat(img0, img1, img);
    /*imshow("img0", img0);
    imshow("img1", img1);
    imshow("img", img);*/

    cv::waitKey(0);

    return 0;
}
