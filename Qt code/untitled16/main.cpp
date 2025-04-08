#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat gray = cv::imread("1.jpeg", cv::IMREAD_GRAYSCALE);

    cv::Mat smallImg, bigImg0, bigImg1, bigImg2;
    cv::resize(gray, smallImg, cv::Size(15, 15), 0, 0, cv::INTER_AREA);
    cv::resize(smallImg, bigImg0, cv::Size(30, 30), 0, 0, cv::INTER_NEAREST);
    cv::resize(smallImg,bigImg1, cv::Size(30, 30), 0, 0, cv::INTER_LINEAR);
    cv::resize(smallImg, bigImg2, cv::Size(30, 30), 0, 0, cv::INTER_CUBIC);
    cv::namedWindow("smallImg", cv::WINDOW_NORMAL);
    imshow("smallImg", smallImg);
    cv::namedWindow("bigImg0", cv::WINDOW_NORMAL);
    imshow("bigImg0", bigImg0);
    cv::namedWindow("bigImg1", cv::WINDOW_NORMAL);
    imshow("bigImg1", bigImg1);
    cv::namedWindow("bigImg2", cv::WINDOW_NORMAL);
    imshow("bigImg2", bigImg2);

    cv::waitKey(0);

    return 0;
}
