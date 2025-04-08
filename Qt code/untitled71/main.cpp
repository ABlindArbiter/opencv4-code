#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main() {
    // 打开摄像头（0表示默认摄像头，也可以替换为视频文件路径）
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "无法打开摄像头！" << endl;
        return -1;
    }

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) {
            cerr << "无法获取视频帧！" << endl;
            break;
        }

        // 转换为HSV颜色空间
        Mat hsv;
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        // 定义红色和蓝色的HSV阈值范围
        // 红色有两个范围（0-10和160-180）
        Mat mask_red1, mask_red2, mask_red;
        inRange(hsv, Scalar(0, 100, 100), Scalar(10, 255, 255), mask_red1);
        inRange(hsv, Scalar(160, 100, 100), Scalar(180, 255, 255), mask_red2);
        bitwise_or(mask_red1, mask_red2, mask_red);

        // 蓝色范围
        Mat mask_blue;
        inRange(hsv, Scalar(100, 100, 100), Scalar(130, 255, 255), mask_blue);

        // 形态学操作（开运算和闭运算）去除噪声
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
        morphologyEx(mask_red, mask_red, MORPH_OPEN, kernel);
        morphologyEx(mask_red, mask_red, MORPH_CLOSE, kernel);
        morphologyEx(mask_blue, mask_blue, MORPH_OPEN, kernel);
        morphologyEx(mask_blue, mask_blue, MORPH_CLOSE, kernel);

        // 查找轮廓
        vector<vector<Point>> contours_red, contours_blue;
        findContours(mask_red, contours_red, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        findContours(mask_blue, contours_blue, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        // 绘制检测结果
        for (const auto& cnt : contours_red) {
            double area = contourArea(cnt);
            if (area > 100) { // 过滤小面积噪声
                Rect rect = boundingRect(cnt);
                rectangle(frame, rect, Scalar(0, 0, 255), 2);
                putText(frame, "Red", Point(rect.x, rect.y - 10), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(0, 0, 255), 2);
            }
        }

        for (const auto& cnt : contours_blue) {
            double area = contourArea(cnt);
            if (area > 100) {
                Rect rect = boundingRect(cnt);
                rectangle(frame, rect, Scalar(255, 0, 0), 2);
                putText(frame, "Blue", Point(rect.x, rect.y - 10), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(255, 0, 0), 2);
            }
        }

        // 显示结果
        imshow("Color Detection", frame);
        if (waitKey(1) == 27) { // 按ESC退出
            break;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
