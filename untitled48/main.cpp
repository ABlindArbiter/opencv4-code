#include <opencv2/opencv.hpp>

int main()
{
    //读取图像，黑白图像边缘检测结果较为明显
    cv::Mat img = imread("12.jpg", cv::IMREAD_ANYCOLOR);

    cv::Mat resultX, resultY, resultXY;

    //X方向一阶边缘
    Sobel(img, resultX, CV_16S, 1, 0, 3);
    convertScaleAbs(resultX, resultX);

    //Y方向一阶边缘
    Sobel(img, resultY, CV_16S, 0, 1, 3);
    convertScaleAbs(resultY, resultY);

    //整幅图像的一阶边缘
    resultXY = resultX + resultY;

    //显示图像
    imshow("resultX", resultX);
    imshow("resultY", resultY);
    imshow("resultXY", resultXY);

    cv::waitKey(0);

    return 0;
}
