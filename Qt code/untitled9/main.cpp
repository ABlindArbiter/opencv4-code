#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    float a[12] = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 0};
    cv::Mat img = cv::Mat(3, 4, CV_32FC1, a);
    cv::Mat imgs = cv::Mat(2, 3, CV_32FC2, a);
    /*img:
      0,0：1   1,0：2   2,0：3   3,0：4
      0,1：5   1,1：10  2,1：6   3,1：7
      0,2：8   1,2：9   2,2：10  3,2：0
      imgs:
      0,0：1 2    1,0：3 4   2,0：5 10
      0,1：6 7    1,1：8 9   2,1：10 0*/
    double minVal, maxVal;
    cv::Point minIdx, maxIdx;

    cv::minMaxLoc(img, &minVal, &maxVal, &minIdx, &maxIdx);
    std::cout << "img最大：" << maxVal << " 位置：" << maxIdx << std::endl;//牛波一，可是有2个10啊？
    std::cout << "img最小：" << minVal << " 位置：" << minIdx << std::endl;

    cv::Mat imgs_re = imgs.reshape(1, 4);//(通道,行数)
    cv::minMaxLoc(imgs_re, &minVal, &maxVal, &minIdx, &maxIdx);
    std::cout << "imgs最大：" << maxVal << " 位置：" << maxIdx << std::endl;//难不成是算第一个？
    std::cout << "imgs最小：" << minVal << " 位置：" << minIdx << std::endl;

    return 0;
}
