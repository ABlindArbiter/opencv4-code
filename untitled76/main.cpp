#include <opencv2/opencv.hpp>
#include <iostream>

// 已知矩形标志物的实际宽度（单位：厘米）
const double KNOWN_WIDTH = 5.32;
// 已知矩形标志物的实际高度（单位：厘米）
const double KNOWN_HEIGHT = 8.50;
// 已知矩形标志物到摄像机的距离（单位：厘米）
const double KNOWN_DISTANCE = 50.0;

// 找到图像中的矩形标志物
cv::RotatedRect find_marker(const cv::Mat& image) {
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0);
    cv::Mat edged;
    cv::Canny(gray, edged, 35, 125);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(edged, contours, hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

    if (contours.empty()) {
        return cv::RotatedRect();
    }

    int max_index = 0;
    double max_area = cv::contourArea(contours[0]);
    for (size_t i = 1; i < contours.size(); ++i) {
        double area = cv::contourArea(contours[i]);
        if (area > max_area) {
            max_area = area;
            max_index = static_cast<int>(i);
        }
    }

    return cv::minAreaRect(contours[max_index]);
}

// 计算摄像机的焦距
double calculate_focal_length(double known_width, double known_distance, double per_width) {
    return (per_width * known_distance) / known_width;
}

int main() {
    // 读取包含矩形标志物的图像
    cv::Mat image = cv::imread("marker_image.jpg");
    if (image.empty()) {
        std::cerr << "无法读取图像，请检查图像路径。" << std::endl;
        return -1;
    }

    // 找到矩形标志物
    cv::RotatedRect marker = find_marker(image);
    if (marker.size.width <= 0) {
        std::cerr << "未找到矩形标志物，请检查图像。" << std::endl;
        return -1;
    }

    // 获取矩形标志物在图像中的宽度
    double per_width = marker.size.width;
    // 计算焦距
    double focal_length = calculate_focal_length(KNOWN_WIDTH, KNOWN_DISTANCE, per_width);
    std::cout << "摄像机的焦距是: " << focal_length << " 像素" << std::endl;

    // 在图像上绘制矩形标志物
    std::vector<cv::Point2f> box_points;
    cv::boxPoints(marker, box_points);
    std::vector<cv::Point> int_box_points;
    for (const auto& point : box_points) {
        int_box_points.emplace_back(static_cast<int>(point.x), static_cast<int>(point.y));
    }
    cv::polylines(image, int_box_points, true, cv::Scalar(0, 255, 0), 2);

    std::string text = "Focal Length: " + std::to_string(focal_length) + " pixels";
    cv::putText(image, text, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

    // 显示图像
    cv::imshow("Marker Detection", image);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
