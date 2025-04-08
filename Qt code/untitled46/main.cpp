#include <opencv2/opencv.hpp>

int main()
{
    //读取两幅含有人脸图像
    cv::Mat img1 = imread("12.jpg", cv::IMREAD_COLOR);
    cv::Mat img2 = imread("13.jpeg", cv::IMREAD_COLOR);

    cv::Mat result1, result2, result3, result4;

    //验证不同滤波器直径的滤波效果
    bilateralFilter(img1, result1, 9, 50, 25 / 2);
    bilateralFilter(img1, result2, 23, 50, 25 / 2);

    //验证不同标准差值的滤波效果
    bilateralFilter(img2, result3, 9, 9, 9);
    bilateralFilter(img2, result4, 9, 200, 200);

    //显示原图
    imshow("img1", img1);
    imshow("img2", img2);
    //显示不同滤波器直径滤波结果
    imshow("result1", result1);
    imshow("result2", result2);
    //不同标准差值滤波结果
    imshow("result3 ", result3);
    imshow("result4", result4);

    cv::waitKey(0);

    return 0;
}
