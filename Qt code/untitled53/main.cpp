#include <opencv2/opencv.hpp>

int main()
{
    //读取图像，黑白图像边缘检测结果较为明显
    cv::Mat img = imread("12.jpg", cv::IMREAD_ANYDEPTH);
    cv::Mat resultHigh, resultLow, resultG;

    //高阈值检测图像边缘
    Canny(img, resultHigh, 100, 200, 3);

    //低阈值检测图像边缘
    Canny(img, resultLow, 20, 40, 3);

    //高斯模糊后检测图像边缘
    GaussianBlur(img, resultG, cv::Size(3, 3), 5);
    Canny(resultG, resultG, 100, 200, 3);

    //显示图像
    imshow("resultHigh", resultHigh);
    imshow("resultLow", resultLow);
    imshow("resultG", resultG);

    cv::waitKey(0);

    return 0;
}
