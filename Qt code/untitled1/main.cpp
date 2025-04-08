#include <opencv2/opencv.hpp>

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

    while (true) {
        cv::Mat frame;

        // 读取当前帧
        cap >> frame;

        // 检查帧是否为空
        if (frame.empty()) {
            std::cerr << "Error: Could not read frame" << std::endl;
            break;
        }

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
