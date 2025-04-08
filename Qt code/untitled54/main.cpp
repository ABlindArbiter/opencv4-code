#include <opencv2/opencv.hpp>

int main()
{
    //构建掩膜矩阵，用于求取像素之间的距离
    cv::Mat a = (cv::Mat_<uchar>(5, 5) << 1, 1, 1, 1, 1,
             1, 1, 0, 1, 1,
             1, 1, 0, 1, 1,
             1, 1, 1, 1, 1,
             1, 1, 1, 1, 1);
    cv::Mat dist_L1, dist_L2, dist_C, dist_L1W;

    //计算街区距离
    distanceTransform(a, dist_L1, 1, 3, CV_8U);
    std::cout << "街区距离：" << std::endl << dist_L1 << std::endl;

    //计算欧氏距离
    distanceTransform(a, dist_L2, 2, 3, CV_8U);
    std::cout << "欧氏距离：" << std::endl << dist_L2 << std::endl;

    //计算棋盘距离
    distanceTransform(a, dist_C, 3, 3, CV_8U);
    std::cout << "棋盘距离：" << std::endl << dist_C << std::endl;

    //对图像进行距离变换
    cv::Mat rice = imread("3.jpeg", cv::IMREAD_GRAYSCALE);
    cv::Mat riceBW, riceBW_INV;

    //将图像转成二值图像，同时把黑白区域颜色互换
    threshold(rice, riceBW, 50, 255, cv::THRESH_BINARY);
    threshold(rice, riceBW_INV, 50, 255, cv::THRESH_BINARY_INV);

    //距离变换
    cv::Mat dist_INV;
    distanceTransform(riceBW, dist_INV, 1, 3, CV_32F);  //为了提高精度，将数据类型设成CV_32F
    convertScaleAbs(dist_INV, dist_INV, 1, 0);

    //显示变换结果
    imshow("RiceBW", riceBW);
    imshow("RiceBW_INV", riceBW_INV);
    imshow("dist_INV", dist_INV);

    cv::waitKey(0);
    return 0;
}
