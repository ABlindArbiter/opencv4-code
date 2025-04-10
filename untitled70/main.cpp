#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//绘制轮廓函数
void drawapp(Mat result, Mat img2)
{
    for (int i = 0; i < result.rows; i++)
    {
        //最后一个坐标点与第一个坐标点相通
        if (i == result.rows - 1)
        {
            Vec2i point1 = result.at<Vec2i>(i);
            Vec2i point2 = result.at<Vec2i>(0);
            line(img2, point1, point2, Scalar(0, 255), 2, 8, 0);
            break;
        }
        Vec2i point1 = result.at<Vec2i>(i);
        Vec2i point2 = result.at<Vec2i>(i + 1);
        line(img2, point1, point2, Scalar(0, 255), 2, 8, 0);
    }
}

int main()
{
    Mat img = imread("21.jpg");
    if (img.empty())
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }
    // 边缘检测
    Mat canny;
    Canny(img, canny, 80, 160, 3, false);
    Mat kernel = getStructuringElement(0, Size(3, 3));
    dilate(canny, canny, kernel);

    // 轮廓提取与绘制
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(canny, contours, hierarchy, 0, 2, Point());

    // 绘制多边形
    for (int t = 0; t < contours.size(); t++)
    {
        //用最小外接矩形求取轮廓中心
        RotatedRect rect = minAreaRect(contours[t]);
        Point2f center = rect.center;
        circle(img, center, 2, Scalar(0, 255, 0), 2, 8, 0);

        Mat result;
        approxPolyDP(contours[t], result, 4, true);  // 多边形逼近
        drawapp(result, img);
        cout << "corners : " << result.rows << endl;
        // 判断形状和轮廓数量
        if (result.rows == 3)
        {
            putText(img, "triangle", center, 0, 1, Scalar(0, 255, 0), 1, 8);
        }
        if (result.rows == 4)
        {
            putText(img, "rectangle", center, 0, 1, Scalar(0, 255, 0), 1, 8);
        }
        if (result.rows == 8)
        {
            putText(img, "polygon8", center, 0, 1, Scalar(0, 255, 0), 1, 8);
        }
        if (result.rows > 12)
        {
            putText(img, "circle", center, 0, 1, Scalar(0, 255, 0), 1, 8);
        }
    }

    imshow("result", img);
    waitKey(0);
    return 0;
}
