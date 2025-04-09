#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void nothing(int, void*) {}

int slow = 144, sup = 255, vlow = 88, vup = 255;
//123 238 115 204
//开灯 144 255 88 255
//关灯 189 255 69 176
int main() {
    // 1. 相机标定参数（需预先标定）
    Mat cameraMatrix = (Mat_<double>(3, 3) <<
                            958.9339890647665, 0, 673.0034964288041,
                        0, 951.6796766912036, 413.8343790787427,
                        0, 0, 1);
    Mat distCoeffs = Mat::zeros(4, 1, CV_64F);

    // 1. 初始化摄像头
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Error: Failed to open camera." << endl;
        return -1;
    }

    // 创建窗口
    namedWindow("img2", WINDOW_NORMAL);
    namedWindow("检测结果", WINDOW_NORMAL);
    namedWindow("处理过程", WINDOW_NORMAL);

    // 创建滑动条
    cv::createTrackbar("Slow", "img2", &slow, 255, nothing);
    cv::createTrackbar("Sup", "img2", &sup, 255, nothing);
    cv::createTrackbar("Vlow", "img2", &vlow, 255, nothing);
    cv::createTrackbar("Vup", "img2", &vup, 255, nothing);

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        // 2. 转换到HSV颜色空间
        Mat hsv;
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        // 3. 分离HSV通道
        vector<Mat> hsvChannels;
        split(hsv, hsvChannels);
        Mat H = hsvChannels[0], S = hsvChannels[1], V = hsvChannels[2];

        // 4. 创建红色掩膜
        Mat red_mask_low, red_mask_high, red_mask, s1, v1, blue_mask, mask;
        inRange(H, 0, 15, red_mask_low);     // 低红色范围
        inRange(H, 160, 180, red_mask_high); // 高红色范围
        inRange(H, 100, 124, blue_mask);
        bitwise_or(red_mask_low, red_mask_high, red_mask);
        bitwise_or(blue_mask, red_mask, mask);
        inRange(S, slow, sup, s1);

        // 5. 通道相减（H通道原始值 - S通道原始值）
        inRange(V, vlow, vup, v1);
        Mat diff;
        subtract(V, S, diff, noArray(), CV_16S);  // 使用原始通道值
        convertScaleAbs(diff, diff);  // 转换为CV_8U类型

        // 6. 结合掩膜
        Mat target;
        bitwise_and(diff, mask, target);
        // 仅在红色区域处理
        bitwise_and(target, s1, target);
        bitwise_and(target, v1, target);

        // GaussianBlur(target, target, Size(15, 15), 0);

        // 7. 二值化处理
        Mat binary;
        threshold(target, binary, 25, 255, THRESH_BINARY);

        // 8. 形态学操作
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
        morphologyEx(binary, binary, MORPH_OPEN, kernel);
        //GaussianBlur(binary, binary, Size(15, 15), 0);
        //GaussianBlur(binary, binary, Size(15, 15), 0);

        // 3. 检测物体
        vector<vector<Point>> contours;
        findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        if (!contours.empty()) {
            // 4. 计算像素高度
            // 找最大轮廓
            int maxIdx = 0;
            double maxArea = contourArea(contours[0]);
            for (size_t i = 1; i < contours.size(); i++) {
                double area = contourArea(contours[i]);
                if (area > maxArea) {
                    maxArea = area;
                    maxIdx = i;
                }
            }
            Rect box = boundingRect(contours[maxIdx]);
            int pixelHeight = box.height;

            // 5. 计算距离 0.85
            double actualHeight = 0.053;
            double distance = (actualHeight * cameraMatrix.at<double>(0, 0)) / pixelHeight - 0.14;
            cout << "Distance: " << distance << " meters" << endl;

            // 绘制结果
            RotatedRect rect = minAreaRect(contours[maxIdx]);
            Point2f points[4];
            rect.points(points);
            for (int i = 0; i < 4; i++) {
                line(frame, points[i], points[(i + 1) % 4], Scalar(0, 255, 0), 2);
            }
            circle(frame, rect.center, 5, Scalar(0, 0, 255), -1);
        }

        // 显示结果
        imshow("检测结果", frame);
        imshow("处理过程", binary);

        // 等待按键事件
        if (waitKey(30) == 27) {
            break;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
