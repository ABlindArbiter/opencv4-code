#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; //opencv的命名空间
using namespace std;

//主函数
int main()
{
    //生成用于膨胀的原图像
    Mat src = (Mat_<uchar>(6, 6) << 0, 0, 0, 0, 255, 0,
               0, 255, 255, 255, 255, 255,
               0, 255, 255, 255, 255, 0,
               0, 255, 255, 255, 255, 0,
               0, 255, 255, 255, 255, 0,
               0, 0, 0, 0, 0, 0);
    Mat struct1, struct2;
    struct1 = getStructuringElement(0, Size(3, 3));//矩形结构元素
    struct2 = getStructuringElement(1, Size(3, 3));//十字型结构元素

    Mat dilateSrc; //存放膨胀后的图像
    dilate(src, dilateSrc, struct2);
    namedWindow("src", WINDOW_GUI_NORMAL);
    namedWindow("dilateSrc", WINDOW_GUI_NORMAL);
    imshow("src", src);
    imshow("dilateSrc", dilateSrc);

    cout << "文字膨胀验证" << endl;
    waitKey(0);//等待函数用于显示图像,按下键盘任意键后退出

    Mat LearnCV_black = imread("15.png");

    Mat dilate_black1, dilate_black2;
    //黑背景图像腐蚀
    dilate(LearnCV_black, dilate_black1, struct1);
    dilate(LearnCV_black, dilate_black2, struct2);
    imshow("LearnCV_black", LearnCV_black);
    imshow("dilate_black1", dilate_black1);
    imshow("dilate_black2", dilate_black2);

    cout << "文字膨胀" << endl;
    waitKey(0);//等待函数用于显示图像,按下键盘任意键后退出

    return 0;

}
