#include <opencv2/opencv.hpp>


int main()
{
    cv::Mat equalLena = imread("2.jpeg", cv::IMREAD_ANYDEPTH);
    //验证方框滤波算法的数据矩阵
    float points[25] = { 1,2,3,4,5,
                        6,7,8,9,10,
                        11,12,13,14,15,
                        16,17,18,19,20,
                        21,22,23,24,25 };
    cv::Mat data(5, 5, CV_32FC1, points);
    //将CV_8U类型转换成CV_32F类型
    cv::Mat equalLena_32F;
    equalLena.convertTo(equalLena_32F, CV_32F, 1.0 / 255);
    cv::Mat resultNorm, result, dataNorm, dataSqr, equalLena_32FSqr;
    //方框滤波函数boxFilter()和sqrBoxFilter()
    boxFilter(data, dataNorm, -1, cv::Size(3, 3), cv::Point(-1, -1), true); //进行归一化
    boxFilter(equalLena, resultNorm, -1, cv::Size(3, 3), cv::Point(-1, -1), true); //进行归一化
    boxFilter(data, result, -1, cv::Size(3, 3), cv::Point(-1, -1), false); //不
    boxFilter(equalLena, result, -1, cv::Size(3, 3), cv::Point(-1, -1), false); //不
    sqrBoxFilter(data, dataSqr, -1, cv::Size(3, 3), cv::Point(-1, -1),
                 true, cv::BORDER_CONSTANT); //进行归一化
    sqrBoxFilter(equalLena_32F, equalLena_32FSqr, -1, cv::Size(3, 3), cv::Point(-1, -1),
                 false, cv::BORDER_CONSTANT); //不
    sqrBoxFilter(equalLena_32F, equalLena_32FSqr, -1, cv::Size(3, 3), cv::Point(-1, -1),
                 true, cv::BORDER_CONSTANT);
    //std::cout << equalLena_32F << std::endl;
    imshow("resultNorm", resultNorm);
    imshow("result", result);
    imshow("equalLena_32FSqr", equalLena_32FSqr);

    cv::waitKey(0);

    return 0;
}
