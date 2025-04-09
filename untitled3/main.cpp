#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 创建一个VideoCapture对象
    cv::VideoCapture cap(0); // 参数0表示打开默认摄像头

    // 检查摄像头是否成功打开
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    // 创建一个窗口用于显示视频
    cv::namedWindow("Camera", cv::WINDOW_AUTOSIZE);

    // 用于计算FPS的变量
    int frame_count = 0;
    double fps = 0.0;
    cv::TickMeter tick_meter;

    while (true) {
        cv::Mat frame;

        // 开始计时
        tick_meter.start();

        // 读取当前帧
        cap >> frame;

        // 检查帧是否为空
        if (frame.empty()) {
            std::cerr << "Error: Could not read frame" << std::endl;
            break;
        }

        // 停止计时
        tick_meter.stop();

        // 计算FPS
        frame_count++;
        if (frame_count >= 10) { // 每10帧计算一次FPS
            fps = frame_count / tick_meter.getTimeSec();
            tick_meter.reset();
            frame_count = 0;
        }

        // 在帧上显示FPS
        std::string fps_text = "FPS: " + std::to_string(fps);
        cv::putText(frame, fps_text, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 0, 0), 2);

        // 显示当前帧
        cv::imshow("Camera", frame);

        // 按下ESC键退出
        if (cv::waitKey(30) == 27) {
            break;
        }
    }

    // 释放摄像头
    cap.release();

    // 销毁窗口
    cv::destroyAllWindows();

    return 0;
}
