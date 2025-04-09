#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat noobcv = cv::imread("2.jpeg"); 
    cv::Mat ROI1, ROI2, ROI2_copy, mask, img2, img_copy, img_copy2;

    cv::resize(noobcv, mask, cv::Size(200, 200));
    img2 = img;
    img.copyTo(img_copy2);
    cv::copyTo(img, img_copy2, img);
    cv::Rect rect (206, 206, 200, 200);

    ROI1 = img(rect);//截图
    if (img.rows >= 406 && img.cols >= 406)
    {
        cv::Rect rect(206, 206, 200, 200);
        ROI1 = img(rect); // 截图
    } else
    {
        std::cerr << "裁剪区域超出图像范围！" << std::endl;
        return -1;
    }

    ROI2 = img(cv::Range(100, 300), cv::Range(100, 300));
    img(cv::Range(100, 300), cv::Range(100, 300)).copyTo(ROI2_copy);
    if (img.rows >= 300 && img.cols >=300) {
        ROI2 = img(cv::Range(10, 10), cv::Range(10, 10));
        img(cv::Range(10, 10), cv::Range(10, 10)).copyTo(ROI2_copy);
    } else {
        std::cerr << "ROI2 裁剪区域超出图像范围！" << std::endl;
        return -1;
    }/**/
    mask.copyTo(ROI1);
    imshow("加noobcv", img);
    // imshow("ROI对ROI2影响", ROI2);
    // imshow("深拷贝ROI2", ROI2_copy);

    cv::circle(img, cv::Point(300, 300), 20, cv::Scalar(0, 0, 255), -1);
    imshow("浅拷贝", img2);
    // imshow("深拷贝img", img_copy);
    imshow("深拷贝img2", img_copy2);
    imshow("画圆", ROI1);

    cv::waitKey(0);

    return 0;
}
