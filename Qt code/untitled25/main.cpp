#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int value;
static void callBack(int, void*);
Mat img1, img2;

int main()
{
    img1 = imread("1.jpeg");
    if (!img1.data)
    {
        cout << "请确认是否输入正确的图像文件" << endl;
        return -1;
    }
    namedWindow("滑动条改变图像亮度");
    imshow("滑动条改变图像亮度", img1);
    value = 100;

    createTrackbar("亮度值百分比", "滑动条改变图像亮度", &value, 600, callBack, 0);
    waitKey(0);
    return 0;
}

static void callBack(int, void*)
{
    float a = value / 100.0;
    img2 = img1 * a;
    imshow("滑动条改变图像亮度", img2);
}
