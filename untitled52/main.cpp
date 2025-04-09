#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
#include<vector>
using namespace cv;
using namespace std;


int main()
{
    // 打开摄像头
    VideoCapture cap(0);
    // if (!cap.isOpened()) {
    //     cout << "Error: Failed to open camera." << endl;
    //     return -1;
    // }
    while (true)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty()) {
            cout << "Error: Failed to capture frame." << endl;

            break;
        }
        //imshow("原图", frame);



        Mat _hsv;
        cvtColor(frame, _hsv, COLOR_BGR2HSV);
        //blur(hsv, hsv, Size(3, 3));
        GaussianBlur(_hsv, _hsv, Size(5, 5), 0);
        //
        Mat str=getStructuringElement(0,Size(13,13),Point(-1,-1));
        // morphologyEx(_hsv,_hsv,MORPH_OPEN,str);
        morphologyEx(_hsv,_hsv,MORPH_OPEN,str);
        dilate(_hsv,_hsv,str);
        dilate(_hsv,_hsv,str);
        erode(_hsv,_hsv,str);
        erode(_hsv,_hsv,str);
        //
        Mat lower_hue_range;
        Mat upper_hue_range;
        inRange(_hsv, Scalar(0, 100, 100), Scalar(10, 255, 255), lower_hue_range);
        inRange(_hsv, Scalar(156, 100, 100), Scalar(180, 255, 255), lower_hue_range);
        inRange(_hsv, Scalar(100, 100, 100), Scalar(124, 255, 255), upper_hue_range);
        // 合并掩码
        Mat hsv;
        bitwise_or(lower_hue_range, upper_hue_range, hsv);
        imshow("hsv", hsv);
        // 色块轮廓
        vector<vector<Point>> _contours;
        findContours(hsv, _contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        // 排序
        if (!_contours.empty())
        {
            int maxIndex = 0;
            double maxArea = contourArea(_contours[0]);

            // 遍历所有轮廓
            for (int i = 1; i < _contours.size(); i++) {
                double area = contourArea(_contours[i]);
                if (area > maxArea) {
                    maxArea = area;
                    maxIndex = static_cast<int>(i);
                }
            }
            // 计算矩形
            RotatedRect rect =  minAreaRect(_contours[maxIndex]);
            Point2f points[4];
            rect.points(points);
            Point2f cpt = rect.center;
            // 绘制矩形
            for (int i = 0; i < 4; i++)
            {
                line(frame, points[i], points[(i + 1) % 4], Scalar(0, 255, 0), 2);
            }
            // 绘制矩形中心点
            circle(frame, cpt, 5, Scalar(0, 0, 255), -1);
        }
        imshow("Frame", frame);

        if (waitKey(30) == 27){
            break;\
        }

    }
    cap.release();
    return 0;


}
