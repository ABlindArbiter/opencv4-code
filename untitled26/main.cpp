#include <opencv2/opencv.hpp>

cv::Mat img, imgPoint;
cv::Point prePoint;
void mouse(int event, int x, int y, int flags, void*);

int main()
{
    img = cv::imread("1.jpeg");
    img.copyTo(imgPoint);
    cv::imshow("1", img);
    cv::imshow("2", imgPoint);
    cv::setMouseCallback("1", mouse, 0);

    cv::waitKey(0);

    return 0;
}

void mouse(int event, int x, int y, int flags, void*)
{
    if(event == cv::EVENT_RBUTTONDOWN)
    {
        std::cout << "put laftmouse" << std::endl;
    }
    if(event == cv::EVENT_LBUTTONDOWN)
    {
        prePoint = cv::Point(x, y);
        std::cout << "the start" << prePoint << std::endl;
    }
    if(event == cv::EVENT_MOUSEMOVE && (flags & cv::EVENT_FLAG_LBUTTON))
    {
        imgPoint.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y, x - 1) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y, x + 1) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y - 1, x) = cv::Vec3b(0, 0, 255);
        imgPoint.at<cv::Vec3b>(y + 1, x) = cv::Vec3b(0, 0, 255);
        cv::imshow("2", imgPoint);//改变像素

        cv::Point pt (x, y);
        cv::line(img, prePoint, pt, cv::Scalar(0, 0, 255), 2, 5, 0);
        prePoint = pt;
        cv::imshow("1", img);//绘制直线
    }
}
