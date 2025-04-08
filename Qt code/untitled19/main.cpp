#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("5.png");
    cv::Point2f src_points[4];
    cv::Point2f dst_points[4];
    //原（Image Watch查看）
    src_points[0] = cv::Point2f(94.0, 374.0);
    src_points[1] = cv::Point2f(507.0, 380.0);
    src_points[2] = cv::Point2f(1.0, 623.0);
    src_points[3] = cv::Point2f(627.0, 627.0);
    //期望
    dst_points[0] = cv::Point2f(0.0, 0.0);
    dst_points[0] = cv::Point2f(627.0, 0.0);
    dst_points[0] = cv::Point2f(0.0, 627.0);
    dst_points[0] = cv::Point2f(627.0, 627.0);

    cv::Mat rotation, img_warp;
    rotation = getPerspectiveTransform(src_points, dst_points);//计算透视变换矩阵
    warpPerspective(img, img_warp, rotation, img.size());//透视变换投影
    imshow("img", img);
    imshow("img_warp", img_warp);

    cv::waitKey(0);

    return 0;
}
