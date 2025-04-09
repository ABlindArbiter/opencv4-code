#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpeg", cv::IMREAD_GRAYSCALE);

    cv::Mat img_x, img_y, img_xy;
    flip(img, img_x, 0);
    flip(img, img_y, 1);
    flip(img, img_xy, -1);
    imshow("x", img_x);
    imshow("y", img_y);
    imshow("xy", img_xy);

    cv::waitKey(0);

    return 0;
}
