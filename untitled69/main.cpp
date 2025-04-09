#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("19.jpg");
    if (img.empty())
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }
    Mat img1;
    img.copyTo(img1);  //该拷贝用来绘制最大外接矩形
    Mat img2;
    img.copyTo(img2);  //该拷贝用来绘制最小外接矩形
    //imshow("img", img);

    //去除噪声与二值化
    Mat canny;
    Canny(img, canny, 80, 160, 3, false);
    imshow("canny", canny);

    //膨胀运算，将细小缝隙填补
    Mat kernel = getStructuringElement(0, Size(3, 3));
    dilate(canny, canny, kernel);

    // 轮廓发现与绘制
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(canny, contours, hierarchy, 0, 2, Point());

    //寻找轮廓的外接矩形
    for (int n = 0; n < contours.size(); n++)
    {
        // 最大外接矩形
        Rect rect = boundingRect(contours[n]);
        rectangle(img1, rect, Scalar(0, 255, 0), 2, 8, 0);

        // 最小外接矩形
        RotatedRect min_rect = minAreaRect(contours[n]);
        Point2f points[4];
        min_rect.points(points);  //读取最小外接矩形的4个顶点
        Point2f cpt = min_rect.center;  //最小外接矩形的中心

        // 绘制旋转矩形与中心位置
        for (int i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                line(img2, points[i], points[0], Scalar(0, 255, 0), 2, 8, 0);
                break;
            }
            line(img2, points[i], points[i + 1], Scalar(0, 255, 0), 2, 8, 0);
        }
        circle(img2, cpt, 2, Scalar(255, 0, 0), 2, 8, 0);
    }
    //输出绘制的外接矩形的结果
    imshow("max", img1);
    imshow("min", img2);
    waitKey(0);
    return 0;
}
