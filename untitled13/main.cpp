#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::Mat img_B, img_B_V, gray_B, gray_B_V, gray_T, gray_T_V, gray_TRUNC;

    threshold(img, img_B, 125, 255, cv::THRESH_BINARY);
    threshold(img, img_B_V, 125, 255, cv::THRESH_BINARY_INV);
    imshow("img_B", img_B);
    imshow("img_B_V", img_B_V);

    threshold(gray, gray_B, 125, 255, cv::THRESH_BINARY);
    threshold(gray, gray_B_V, 125, 255, cv::THRESH_BINARY_INV);
    imshow("gray_B", gray_B);
    imshow("gray_B_V", gray_B_V);

    threshold(gray, gray_T, 125, 255, cv::THRESH_TOZERO);
    threshold(gray, gray_T_V, 125, 255, cv::THRESH_TOZERO_INV);
    imshow("gray_T", gray_T);
    imshow("gray_T_V", gray_T_V);

    threshold(gray, gray_TRUNC, 125, 255, cv::THRESH_TRUNC);
    imshow("gray_TRUNC", gray_TRUNC);
    //
    cv::Mat img_Thr = imread("3.jpeg", cv::IMREAD_GRAYSCALE);
    cv::Mat img_Thr_O, img_Thr_T;
    cv::threshold(img_Thr, img_Thr_O, 100, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::threshold(img_Thr, img_Thr_T, 125, 255, cv::THRESH_BINARY | cv::THRESH_TRIANGLE);
    cv::imshow("img_Thr", img_Thr);
    cv::imshow("img_Thr_O", img_Thr_O);
    cv::imshow("img_Thr_T", img_Thr_T);

    cv::Mat adaptive_mean, adaptive_gauss;
    cv::adaptiveThreshold(img_Thr, adaptive_mean, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 55, 0);
    cv::adaptiveThreshold(img_Thr, adaptive_gauss, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 55, 0);
    imshow("adaptive_mean", adaptive_mean);
    imshow("adaptive_gauss", adaptive_gauss);

    cv::waitKey(0);

    return 0;
}
