#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpg");

    cv::Mat img0 = cv::Mat::zeros(200, 200, CV_8UC1);
    cv::Mat img1 = cv::Mat::zeros(200, 200, CV_8UC1);
    cv::Rect rect0(50, 50, 100, 100);
    img0(rect0) = cv::Scalar(255);
    cv::Rect rect1(100, 100, 100, 100);
    img1(rect1) = cv::Scalar(255);
    cv::imshow("img0", img0);
    cv::imshow("img1", img1);

    cv::Mat myAnd, myOr, myXor, myNot, imgNot;
    bitwise_not(img0, myNot);
    bitwise_and(img0, img1, myAnd);
    bitwise_or(img0, img1, myOr);
    bitwise_xor(img0, img1, myXor);
    bitwise_not(img, imgNot);
    imshow("myAnd", myAnd);
    imshow("myOr", myOr);
    imshow("myXor", myXor);
    imshow("myNot", myNot);
    imshow("img", img);
    imshow("imgNot", imgNot);

    cv::waitKey(0);

    return 0;
}
