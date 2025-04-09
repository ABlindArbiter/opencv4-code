#include <opencv2/opencv.hpp>


int main()
{
    cv::Mat gray = imread("1.jpeg", cv::IMREAD_GRAYSCALE);
    cv::Mat img = imread("2.jpeg", cv::IMREAD_COLOR);

    cv::Mat imgResult3, imgResult9, grayResult3, grayResult9;
    //分别对含有椒盐噪声的彩色图像和灰度图像进行滤波，滤波模板为3×3
    medianBlur(img, imgResult3, 3);
    medianBlur(gray, grayResult3, 3);
    //加大滤波模板，图像滤波结果会变模糊
    medianBlur(img, imgResult9, 9);
    medianBlur(gray, grayResult9, 9);
    //显示滤波处理结果
    imshow("img", img);
    imshow("gray", gray);
    imshow("imgResult3", imgResult3);
    imshow("grayResult3", grayResult3);
    imshow("imgResult9", imgResult9);
    imshow("grayResult9", grayResult9);

    cv::waitKey(0);

    return 0;
}
