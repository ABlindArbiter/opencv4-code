#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    int maxTested = 10; // 测试前10个索引，通常不需要测试更多
    int availableCameras = 0;

    std::cout << "Detecting available cameras...\n";

    for (int i = 0; i < maxTested; ++i) {
        cv::VideoCapture cap(i);
        if (cap.isOpened()) {
            std::cout << "Camera " << i << " is available.\n";
            availableCameras++;
            cap.release(); // 释放摄像头
        }
    }

    std::cout << "Total available cameras: " << availableCameras << std::endl;

    return 0;
}
