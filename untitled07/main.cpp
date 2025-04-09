#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int main()
{
    cv::Mat img = cv::imread("1.jpg");
    if (img.empty())
    {
        std::cout << "未找到" << std::endl;
        return -1;
    }
    cv::Mat HSV;
    cvtColor (img, HSV, cv::COLOR_RGB2HSV);
    cv::Mat imgs0, imgs1, imgs2;
    cv::Mat imgv0, imgv1, imgv2;
    cv::Mat result0, result1, result2;

    cv::Mat imgs[3];
    split(img, imgs);
    imgs0 = imgs[0];
    imgs1 = imgs[1];
    imgs2 = imgs[2];
    //imshow ("B", imgs0);
    //imshow ("G", imgs1);
    //imshow ("R", imgs2);

    //imgs[2] = img;//非常奇怪的一步……“将数组中的通道图像变成不一致”
    merge (imgs, 3, result0);
    //imshow ("result0", result0);
    cv::Mat zero = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
    imgs[1] = zero;//2红1绿0蓝
    imgs[0] = zero;
    merge (imgs, 3, result1);
    cv::imshow ("result1", result1);

    std::vector<cv::Mat> imgv;
    split(HSV, imgv);
    imgv0 = imgv.at(0);
    imgv1 = imgv.at(1);
    imgv2 = imgv.at(2);
    //imshow ("H", imgv0);
    //imshow ("S", imgv1);
    //imshow ("V", imgv2);
    imgv.push_back(HSV);
    merge (imgv, result2);
    //imshow ("result2", result2);

    cv::waitKey(0);

    return 0;
}
