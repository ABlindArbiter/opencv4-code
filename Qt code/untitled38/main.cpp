#include <opencv2/opencv.hpp>

int main()
{
    //待卷积矩阵
    uchar points[25] = { 1,2,3,4,5,
                        6,7,8,9,10,
                        11,12,13,14,15,
                        16,17,18,19,20,
                        21,22,23,24,25 };
    cv::Mat img(5, 5, CV_8UC1, points);
    //卷积模板
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << 1, 2, 1,
                                                0, 0, 0,
                                                1, 2, 1);
    cv::Mat kernel_norm = kernel / 12;  //卷积模板归一化
    //未归一化卷积结果和归一化卷积结果
    cv::Mat result, result_norm;
    filter2D(img, result, CV_32F, kernel, cv::Point(-1, -1), 2, cv::BORDER_CONSTANT);
    filter2D(img, result_norm, CV_32F, kernel_norm, cv::Point(-1,-1),2, cv::BORDER_CONSTANT);
    std::cout << "result:" << std::endl << result << std::endl;
    std::cout << "result_norm:" << std::endl << result_norm << std::endl;
    //图像卷积
    cv::Mat lena = cv::imread("1.jpeg");
    cv::Mat lena_filter;
    filter2D(lena, lena_filter, -1, kernel_norm, cv::Point(-1, -1), 2, cv::BORDER_CONSTANT);
    imshow("lena_filter", lena_filter);
    imshow("lena", lena);
    cv::waitKey(0);
    return 0;
}
