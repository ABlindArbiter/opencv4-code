#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    system("color f0");  //更改输出界面颜色
    cv::Mat sobel_x1,sobel_y1,sobel_x2,sobel_y2, sobel_x3, sobel_y3;  //存放分离的Sobel算子
    cv::Mat scharr_x, scharr_y;  //存放分离的Scharr算子
    cv::Mat sobelX1, sobelX2, sobelX3, scharrX;  //存放最终算子

    //一阶X方向Sobel算子
    getDerivKernels(sobel_x1, sobel_y1, 1, 0, 3);
    sobel_x1 = sobel_x1.reshape(CV_8U, 1);
    sobelX1 = sobel_y1*sobel_x1;  //计算滤波器

    //二阶X方向Sobel算子
    getDerivKernels(sobel_x2, sobel_y2, 2, 0, 5);
    sobel_x2 = sobel_x2.reshape(CV_8U, 1);
    sobelX2 = sobel_y2*sobel_x2;  //计算滤波器

    //三阶X方向Sobel算子
    getDerivKernels(sobel_x3, sobel_y3, 3, 0, 7);
    sobel_x3 = sobel_x3.reshape(CV_8U, 1);
    sobelX3 = sobel_y3*sobel_x3;  //计算滤波器

    //X方向Scharr算子
    getDerivKernels(scharr_x, scharr_y, 1, 0, cv::FILTER_SCHARR);
    scharr_x = scharr_x.reshape(CV_8U, 1);
    scharrX = scharr_y*scharr_x;  //计算滤波器

    //输出结果
    std::cout << "X方向一阶Sobel算子: " << std::endl << sobelX1 << std::endl;
    std::cout << "X方向二阶Sobel算子: " << std::endl << sobelX2 << std::endl;
    std::cout << "X方向三阶Sobel算子: " << std::endl << sobelX3 << std::endl;
    std::cout << "X方向Scharr算子: " << std::endl << scharrX << std::endl;

    cv::waitKey(0);

    return 0;
}
