#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat rotation0, rotation1, img_warp0, img_warp1;
    double angle = 30;//旋转角度
    cv::Size dst_size(img.rows, img.cols);//输出尺寸
    cv::Point2f center(img.rows / 2.0, img.cols / 2.0);//旋转中心
    rotation0 = getRotationMatrix2D (center, angle, 1);//计算仿射变换矩阵
    cv::warpAffine(img, img_warp0, rotation0, dst_size);//仿射变换
    imshow("img_warp0", img_warp0);
    //根据定义3点进行仿射变换
    cv::Point2f src_points[3];
    cv::Point2f dst_points[3];
    src_points[0] = cv::Point2f(0, 0);//原始3点
    src_points[1] = cv::Point2f(0, (float)(img.cols - 1));
    src_points[2] = cv::Point2f((float)(img.rows - 1), (float)(img.cols - 1));
    //变换后3点
    dst_points[0] = cv::Point2f((float)(img.rows) * 0.11, (float)(img.cols) * 0.20);
    dst_points[1] = cv::Point2f((float)(img.rows) * 0.15, (float)(img.cols) * 0.70);
    dst_points[2] = cv::Point2f((float)(img.rows) * 0.81, (float)(img.cols) * 0.85);
    rotation1 = cv::getAffineTransform(src_points, dst_points);//根据对应点求仿射变换矩阵
    warpAffine(img, img_warp1, rotation1, dst_size);//变
    imshow("img_warp1", img_warp1);

    cv::waitKey(0);

    return 0;
}
