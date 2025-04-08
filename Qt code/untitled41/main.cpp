#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat equalLena = imread("1.jpeg", cv::IMREAD_ANYDEPTH);
    cv::Mat equalLena_gauss = imread("2.jpeg", cv::IMREAD_ANYDEPTH);
    cv::Mat equalLena_salt = imread("11.jpeg", cv::IMREAD_ANYDEPTH);

    cv::Mat result_3, result_9; //存放不含噪声滤波结果，后面的数字代表滤波器尺寸
    cv::Mat result_3gauss, result_9gauss; //存放含有高斯噪声滤波结果，后面的数字代表滤波器尺寸
    cv::Mat result_3salt, result_9salt; //存放含有椒盐噪声滤波结果，后面的数字代表滤波器尺寸

    //调用均值滤波函数blur()进行滤波
    blur(equalLena, result_3, cv::Size(3, 3));
    blur(equalLena, result_9, cv::Size(9, 9));
    blur(equalLena_gauss, result_3gauss, cv::Size(3, 3));
    blur(equalLena_gauss, result_9gauss, cv::Size(9, 9));
    blur(equalLena_salt, result_3salt, cv::Size(3, 3));
    blur(equalLena_salt, result_9salt, cv::Size(9, 9));

    //显示不含噪声图像
    imshow("equalLena ", equalLena);
    imshow("result_3", result_3);
    imshow("result_9", result_9);
    //显示含有高斯噪声图像
    imshow("equalLena_gauss", equalLena_gauss);
    imshow("result_3gauss", result_3gauss);
    imshow("result_9gauss", result_9gauss);
    //显示含有椒盐噪声图像
    imshow("equalLena_salt", equalLena_salt);
    imshow("result_3salt", result_3salt);
    imshow("result_9salt", result_9salt);

    cv::waitKey(0);

    return 0;
}
