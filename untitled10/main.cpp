#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    float a[12] = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 0};
    cv::Mat img = cv::Mat(3, 4, CV_32FC1, a);
    cv::Mat imgs = cv::Mat(2, 3, CV_32FC2, a);

    cv::Scalar myMean;
    myMean = mean(imgs);
    std::cout << "imgs平均值：" << myMean << std::endl << "通道一：" << myMean[0] << std::endl
              << "通道二：" << myMean[1] << std::endl << std::endl;

    cv::Mat myMeanMat, myStddevMat;
    cv::meanStdDev(img, myMeanMat, myStddevMat);
    std::cout << "img平均值：" << myMeanMat << std::endl;
    std::cout << "img标准差：" << myStddevMat << std::endl << std::endl;
    cv::meanStdDev(imgs, myMeanMat, myStddevMat);
    std::cout << "imgs平均值：" << myMeanMat << std::endl << std::endl;
    std::cout << "imgs标准差：" << myStddevMat << std::endl;

    return 0;
}
