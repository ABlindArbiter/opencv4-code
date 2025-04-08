#include <opencv2/opencv.hpp>

int main()
{
    system("color FC"); //更改输出界面颜色
    float points[25] = { 1,2,3,4,5,
                        6,7,8,9,10,
                        11,12,13,14,15,
                        16,17,18,19,20,
                        21,22,23,24,25 };
    cv::Mat data(5, 5, CV_32FC1, points);
    //X方向、Y方向联合滤波器的构建
    cv::Mat a = (cv::Mat_<float>(3, 1) << -1, 3, -1);
    cv::Mat b = a.reshape(1, 1);
    cv::Mat ab = a * b;
    //验证高斯滤波的可分离性
    cv::Mat gaussX = cv::getGaussianKernel(3, 1);
    cv::Mat gaussDataXY;
    GaussianBlur(data, gaussDataXY, cv::Size(3, 3), 1, 1, cv::BORDER_CONSTANT);

    sepFilter2D(data,gaussDataXY,-1, gaussX, gaussX, cv::Point(-1,-1),0,cv::BORDER_CONSTANT);
    //输入两种高斯滤波的计算结果
    std::cout << "gaussDataXY=" << std::endl
         << gaussDataXY << std::endl;

    //线性滤波的可分离性
    cv::Mat dataX, dataY, dataXY, dataXY_sep;
    filter2D(data, dataX, -1, a, cv::Point(-1, -1), 0, cv::BORDER_CONSTANT);
    filter2D(data, dataY, -1, b, cv::Point(-1, -1), 0, cv::BORDER_CONSTANT);
    filter2D(dataX, dataXY, -1, b, cv::Point(-1, -1), 0, cv::BORDER_CONSTANT);
    filter2D(dataY, dataXY_sep, -1, a, cv::Point(-1, -1), 0, cv::BORDER_CONSTANT);
    //输出可分离滤波和联合滤波的计算结果
    std::cout << "dataY=" << std::endl
              << dataY << std::endl;
    std::cout << "dataXY=" << std::endl
              << dataXY << std::endl;
    std::cout << "dataXY_sep=" << std::endl
              << dataXY_sep << std::endl;

    //对图像的分离操作
    cv::Mat img = cv::imread("1.jpeg");

    cv::Mat imgX, imgY, imgXY;
    filter2D(img, imgX, -1, a, cv::Point(-1, -1), 0, cv::BORDER_CONSTANT);
    filter2D(img, imgY, -1, b, cv::Point(-1, -1), 0, cv::BORDER_CONSTANT);
    filter2D(img, imgXY, -1, ab, cv::Point(-1, -1), 0, cv::BORDER_CONSTANT);

    imshow("imgXY", imgXY);

    cv::waitKey(0);

    return 0;
}
