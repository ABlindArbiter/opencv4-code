#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat lena = cv::imread("1.jpeg");
    cv::Mat equilena = imread("1.jpeg", cv::IMREAD_ANYDEPTH);
    //生成与原始图像尺寸、数据类型和通道数相同的矩阵
    cv::Mat lena_noise = cv::Mat::zeros(lena.rows, lena.cols, lena.type());
    cv::Mat equalLena_noise = cv::Mat::zeros(lena.rows, lena.cols, equilena.type());
    cv::imshow("1原图", lena);
    cv::imshow("2原图", equilena);
    cv::RNG rng;  //创建一个RNG类
    rng.fill(lena_noise, cv::RNG::NORMAL, 10, 20);  //生成三通道的高斯分布随机数
    rng.fill(equalLena_noise, cv::RNG::NORMAL, 15, 30);  //生成单通道的高斯分布随机数
    imshow("三通道高斯噪声", lena_noise);
    imshow("单通道高斯噪声", equalLena_noise);
    lena = lena + lena_noise;  //在彩色图像中添加高斯噪声
    equilena = equilena + equalLena_noise;  //在灰度图像中添加高斯噪声
    //显示添加高斯噪声后的图像
    imshow("lena添加噪声", lena);
    imshow("equilena添加噪声", equilena);

    cv::waitKey(0);

    return 0;
}
