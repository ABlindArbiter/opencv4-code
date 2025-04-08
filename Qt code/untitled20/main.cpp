#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("6.jpeg");
    cv::Mat img1, img2;
    cv::Point2f center = cv::Point2f(img.cols / 2, img.rows / 2);//原点
    cv::warpPolar(img, img1, cv::Size(300, 600), center, center.x,//出图的原点错了，变成3点了
                  cv::INTER_LINEAR + cv::WARP_POLAR_LINEAR + cv::WARP_INVERSE_MAP);

    cv::warpPolar(img1, img2, cv::Size(img.rows, img.cols), center, center.x,
                  cv::INTER_LINEAR + cv::WARP_POLAR_LINEAR + cv::WARP_INVERSE_MAP);

    imshow("原", img);
    imshow("极变化", img1);
    imshow("逆1", img2);

    cv::waitKey(0);

    return 0;
}
