#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 空回调函数，用于滑动条
void nothing(int, void*) {}

// 创建颜色掩膜的函数
Mat createColorMask(const Mat& hsv, int slow, int sup, int vlow, int vup) {
    // 分离 HSV 通道
    vector<Mat> hsvChannels;
    split(hsv, hsvChannels);
    Mat H = hsvChannels[0], S = hsvChannels[1], V = hsvChannels[2];

    // 创建红色和蓝色掩膜
    Mat red_mask_low, red_mask_high, red_mask, s1, v1, blue_mask, mask;
    inRange(H, 0, 15, red_mask_low);     // 低红色范围
    inRange(H, 160, 180, red_mask_high); // 高红色范围
    inRange(H, 100, 124, blue_mask);
    bitwise_or(red_mask_low, red_mask_high, red_mask);
    bitwise_or(blue_mask, red_mask, mask);

    // 根据滑动条值创建 S 通道和 V 通道的掩膜
    inRange(S, slow, sup, s1);
    inRange(V, vlow, vup, v1);

    // 通道相减
    Mat diff;
    subtract(V, S, diff, noArray(), CV_16S);
    convertScaleAbs(diff, diff);

    // 结合掩膜
    Mat target;
    bitwise_and(diff, mask, target);
    bitwise_and(target, s1, target);
    bitwise_and(target, v1, target);

    return target;
}

// 处理帧的函数
void processFrame(const Mat& frame, const Mat& cameraMatrix, Mat& resultFrame,
                  int slow, int sup, int vlow, int vup, double& distance) {
    // 转换到 HSV 颜色空间
    Mat hsv;
    cvtColor(frame, hsv, COLOR_BGR2HSV);

    // 创建颜色掩膜
    Mat target = createColorMask(hsv, slow, sup, vlow, vup);

    // 二值化处理
    Mat binary;
    threshold(target, binary, 25, 255, THRESH_BINARY);

    // 形态学操作
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    morphologyEx(binary, binary, MORPH_OPEN, kernel);

    // 高斯模糊
    GaussianBlur(binary, binary, Size(15, 15), 0);
    GaussianBlur(binary, binary, Size(15, 15), 0);

    // 检测物体轮廓
    vector<vector<Point>> contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    distance = -1;
    if (!contours.empty()) {
        // 找到最大轮廓
        int maxIdx = 0;
        double maxArea = contourArea(contours[0]);
        for (size_t i = 1; i < contours.size(); i++) {
            double area = contourArea(contours[i]);
            if (area > maxArea) {
                maxArea = area;
                maxIdx = i;
            }
        }
        // 计算像素高度
        Rect box = boundingRect(contours[maxIdx]);
        int pixelHeight = box.height;

        // 避免除零错误
        if (pixelHeight > 0) {
            // 计算距离
            double actualHeight = 0.053;
            distance = (actualHeight * cameraMatrix.at<double>(0, 0)) / pixelHeight - 0.14;
            cout << "Distance: " << distance << " meters" << endl;
        } else {
            cerr << "Error: Pixel height is zero, cannot calculate distance." << endl;
        }

        // 绘制结果
        resultFrame = frame.clone();
        RotatedRect rect = minAreaRect(contours[maxIdx]);
        Point2f points[4];
        rect.points(points);
        for (int i = 0; i < 4; i++) {
            line(resultFrame, points[i], points[(i + 1) % 4], Scalar(0, 255, 0), 2);
        }
        circle(resultFrame, rect.center, 5, Scalar(0, 0, 255), -1);
    } else {
        resultFrame = frame.clone();
    }
}

int main() {
    // 相机标定参数（需预先标定）
    Mat cameraMatrix = (Mat_<double>(3, 3) <<
                            958.9339890647665, 0, 673.0034964288041,
                        0, 951.6796766912036, 413.8343790787427,
                        0, 0, 1);
    Mat distCoeffs = Mat::zeros(4, 1, CV_64F);

    // 初始化摄像头
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error: Failed to open camera." << endl;
        return -1;
    }

    // 创建窗口
    namedWindow("img2", WINDOW_NORMAL);
    namedWindow("检测结果", WINDOW_NORMAL);
    namedWindow("处理过程", WINDOW_NORMAL);

    // 滑动条初始值
    int slow = 189, sup = 255, vlow = 88, vup = 176;
    // 开灯 144 255 88 255
    // 关灯 189 255 69 176

    // 创建滑动条
    cv::createTrackbar("Slow", "img2", &slow, 255, nothing);
    cv::createTrackbar("Sup", "img2", &sup, 255, nothing);
    cv::createTrackbar("Vlow", "img2", &vlow, 255, nothing);
    cv::createTrackbar("Vup", "img2", &vup, 255, nothing);

    Mat frame, resultFrame;
    double distance;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "Error: Failed to read frame from camera." << endl;
            break;
        }

        // 处理当前帧
        processFrame(frame, cameraMatrix, resultFrame, slow, sup, vlow, vup, distance);

        // 显示结果
        imshow("检测结果", resultFrame);
        Mat target = createColorMask(cvtColor(frame, COLOR_BGR2HSV), slow, sup, vlow, vup);
        Mat binary;
        threshold(target, binary, 25, 255, THRESH_BINARY);
        imshow("处理过程", binary);

        // 等待按键事件
        if (waitKey(30) == 27) {
            break;
        }
    }

    // 释放资源
    cap.release();
    destroyAllWindows();
    return 0;
}
