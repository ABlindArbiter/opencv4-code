#include <opencv2/opencv.hpp>

void drawHist(cv::Mat &hist, int type, std::string name)
{
    int hist_w = 512;
    int hist_h = 400;
    int width = 2;
    cv::Mat histImage = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
    cv::normalize(hist, hist, 1, 0, type, -1, cv::Mat());
    for(int i = 1; i <= hist.rows; i++)
    {
        rectangle(histImage, cv::Point(width*(i - 1), hist_h - 1),
                  cv::Point(width* - 1, hist_h - cvRound(hist_h * hist.at<float>(i - 1)) - 1),
                  cv::Scalar(255, 255, 255), -1);
    }
    cv::imshow(name, histImage);
}

int main()
{
    system("color F0");
    cv::Mat img = cv::imread("3.jpeg");
    cv::Mat gray, hist, gray2, hist2, gray3, hist3;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::resize(gray, gray2, cv::Size(), 0.5, 0.5);
    gray3 = cv::imread("2.jpeg", cv::IMREAD_GRAYSCALE);
    const int channels[1] = {0};
    float inRangles[2] = {0, 255};
    const float* rangles[1] = {inRangles};
    const int bins[1] = {256};
    calcHist(&gray, 1, channels, cv::Mat(), hist, 1, bins, rangles);
    calcHist(&gray2, 1, channels, cv::Mat(), hist2, 1, bins, rangles);
    calcHist(&gray3, 1, channels, cv::Mat(), hist3, 1, bins, rangles);
    drawHist(hist, cv::NORM_INF, "hist");
    drawHist(hist2, cv::NORM_INF, "hist2");
    drawHist(hist3, cv::NORM_INF, "hist3");

    double hist_hist = cv::compareHist(hist, hist, cv::HISTCMP_CORREL);
    std::cout << "1_1 256 = " << hist_hist << std::endl;

    double hist_hist2 = cv::compareHist(hist, hist2, cv::HISTCMP_CORREL);
    std::cout << "1_1 256 = " << hist_hist2 << std::endl;

    double hist_hist3 = cv::compareHist(hist, hist3, cv::HISTCMP_CORREL);
    std::cout << "1_1 256 = " << hist_hist3 << std::endl;

    cv::waitKey(0);

    return 0;
}








