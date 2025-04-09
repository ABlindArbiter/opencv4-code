#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat equallena = imread("1.jpeg", cv::IMREAD_ANYDEPTH);
    cv::Mat equallena_gauss = imread("2.jpeg", cv::IMREAD_ANYDEPTH);
    cv::Mat equallena_salt = imread("11.jpeg", cv::IMREAD_ANYDEPTH);

    cv::Mat result_5, result_9;
    cv::Mat result_5gauss, result_9gauss;
    cv::Mat result_5salt, result_9salt;

    GaussianBlur(equallena, result_5, cv::Size(5, 5), 10, 20);
    GaussianBlur(equallena, result_9, cv::Size(9, 9), 10, 20);
    GaussianBlur(equallena_gauss, result_5gauss, cv::Size(5, 5), 10, 20);
    GaussianBlur(equallena_gauss, result_9gauss, cv::Size(9, 9), 10, 20);
    GaussianBlur(equallena_salt, result_5salt, cv::Size(5, 5), 10, 20);
    GaussianBlur(equallena_salt, result_9salt, cv::Size(9, 9), 10, 20);

    //显示不含噪声图像
    imshow("equallena ", equallena);
    imshow("result_5", result_5);
    imshow("result_9", result_9);

    //显示含有高斯噪声图像
    imshow("equallena_gauss", equallena_gauss);
    imshow("result_5gauss", result_5gauss);
    imshow("result_9gauss", result_9gauss);

    //显示含有椒盐噪声图像
    imshow("equallena_salt", equallena_salt);
    imshow("result_5salt", result_5salt);
    imshow("result_9salt", result_9salt);

    cv::waitKey(0);

    return 0;
}
