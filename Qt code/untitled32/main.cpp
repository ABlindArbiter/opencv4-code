#include <opencv2/opencv.hpp>

int main()
{
    system("color F0");//界面颜色
    std::vector<double> positiveData = {2.0, 8.0, 10.0};
    std::vector<double> normalized_L1, normalized_L2, normalized_Inf, normalized_MINMAX;
     //三种归一法
    normalize(positiveData, normalized_L1, 1.0, 0.0, cv::NORM_L1);//绝对值求和归一化
    std::cout << "normalized_L1 = [" << normalized_L1[0] << ", " << normalized_L1[1] << ", "
              << normalized_L1[2] << "]" << std::endl << std::endl;

    normalize(positiveData, normalized_L2, 1.0, 0.0, cv::NORM_L2);//模长归一化
    std::cout << "normalized_L2 = [" << normalized_L2[0] << ", " << normalized_L2[1] << ", "
              << normalized_L1[2] << "]" << std::endl << std::endl;

    normalize(positiveData, normalized_Inf, 1.0, 0.0, cv::NORM_INF);//最大值归一化
    std::cout << "normalized_Inf = [" << normalized_Inf[0] << ", " << normalized_Inf[1] << ", "
              << normalized_Inf[2] << "]" << std::endl << std::endl;

    normalize(positiveData, normalized_MINMAX, 1.0, 0.0, cv::NORM_MINMAX);//偏移归一化
    std::cout << "normalized_MINMAX = [" << normalized_MINMAX[0] << ", " << normalized_MINMAX[1] << ", "
              << normalized_MINMAX[2] << "]" << std::endl << std::endl;


    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat gray, hist;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    const int channels[1] = {0};
    float inRanges[2] = {0, 255};
    const float* ranges[1] = {inRanges};
    const int bins[1] = {256};
    cv::calcHist(&gray, 1, channels, cv::Mat(), hist, 1, bins, ranges);
    int hist_w = 512;
    int hist_h = 400;
    double width = 1;
    cv::Mat histImage_L1 = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
    cv::Mat histImage_Inf = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
    cv::Mat hist_L1, hist_Inf;
    cv::normalize(hist, hist_L1, 1, 0, cv::NORM_L1, -1, cv::Mat());
    for(int i = 1; i <= hist_L1.rows; i++)
    {
        rectangle(histImage_L1, cv::Point(width*(i - 1), hist_h - 1),
                  cv::Point(width* - 1, hist_h - cvRound(30 * hist_h * hist_L1.at<float>(i - 1)) - 1),
                  cv::Scalar(255, 255, 255), -1);
    }
    cv::normalize(hist, hist_Inf, 1, 0, cv::NORM_INF, -1, cv::Mat());
    for(int i = 1; i <= hist_Inf.rows; i++)
    {
        rectangle(histImage_Inf, cv::Point(width*(i - 1), hist_h - 1),
                  cv::Point(width* - 1, hist_h - cvRound(hist_h * hist_Inf.at<float>(i - 1)) - 1),
                  cv::Scalar(255, 255, 255), -1);
    }
    cv::imshow("histImage_L1", histImage_L1);
    cv::imshow("histImage_Inf", histImage_Inf);

    cv::waitKey(0);

    return 0;
}
