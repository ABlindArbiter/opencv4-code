#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

void findcontours(Mat image, vector<vector<Point>> &contours)
{
    Mat gray, binary;
    vector<Vec4i> hierarchy;
    //图像灰度化
    cvtColor(image, gray, COLOR_BGR2GRAY);
    //图像二值化
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
    //寻找轮廓
    findContours(binary, contours, hierarchy, 0, 2);
}

int main()
{
    Mat img = imread("23.jpg");
    Mat img_B = imread("24.png");
    if (img.empty() || img_B.empty())
    {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }

    resize(img_B, img_B, Size(), 0.5, 0.5);
    imwrite("B.png", img_B);
    imshow("B", img_B);

    // 轮廓提取
    vector<vector<Point>> contours1;
    vector<vector<Point>> contours2;
    findcontours(img, contours1);
    findcontours(img_B, contours2);

    // Hu矩计算
    Mat mu2 = moments(contours2[0]);
    Mat hu2;
    HuMoments(mu2, hu2);

    // 轮廓匹配
    for (int n = 0; n < contours1.size(); n++)
    {
        Moments mm = moments(contours1[n]);
        Mat hum;
        HuMoments(mm, hum);

        // 匹配距离
        double dist;
        dist = matchShapes(hum, hu2, CONTOURS_MATCH_I1, 0);
        if (dist < 1)
        {
            drawContours(img, contours1, n, Scalar(0, 255), 3, 8);
        }
    }
    imshow("match result", img);
    return 0;
}
