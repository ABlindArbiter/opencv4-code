#include <opencv2/opencv.hpp>

int main()
{
    //读取图像，黑白图像边缘检测结果较为明显
    cv::Mat img = imread("12.jpg", cv::IMREAD_ANYDEPTH);
    cv::Mat result, result_g, result_G;

    //未进行滤波提取Laplacian边缘
    Laplacian(img, result, CV_16S, 3, 1, 0);
    convertScaleAbs(result, result);

    //滤波后提取Laplacian边缘
    GaussianBlur(img, result_g, cv::Size(3, 3), 5, 0);  //高斯滤波
    Laplacian(result_g, result_G, CV_16S, 3, 1, 0);
    convertScaleAbs(result_G, result_G);

    //显示图像
    imshow("result", result);
    imshow("result_G", result_G);

    cv::waitKey(0);

    return 0;
}
