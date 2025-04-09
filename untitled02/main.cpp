#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{

    cv::Mat img = cv::imread("1.jpg");	// 读取图像
    if (img.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    cv::namedWindow("Image", cv::WINDOW_FREERATIO);	// 创建一个窗口，窗口名为"Image"，窗口属性为自由比例
    cv::imshow("Image", img);						// 显示图像，显示在"Image"窗口上
    cv::waitKey(0);									// 等待按键，0表示无限等待。参数为等待时间，单位为ms
    cv::destroyAllWindows();						// 销毁所有窗口
    return 0;
}
