#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat temp = cv::imread("2.jpeg");
    cv::Mat result;
    matchTemplate(img, temp, result, cv::TM_CCOEFF_NORMED);
    double maxVal, minVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    cv::rectangle(img, cv::Rect(maxLoc.x, maxLoc.y, temp.cols, temp.cols, temp.rows), cv::Scalar(0, 0, 255), 2);
    cv::imshow("原图", img);
    cv::imshow("模板图像", temp);
    //cv::imread("result", result);

    cv::waitKey(0);

    return 0;
}
