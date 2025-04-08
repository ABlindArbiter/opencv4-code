#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    std::vector<cv::Mat> Gauss, Lap;
    int level = 3;
    Gauss.push_back(img);
    for(int i = 0;i < level; i++)
    {
        cv::Mat gauss;
        pyrDown(Gauss[i], gauss);
        Gauss.push_back(gauss);
    }
    for (int i = Gauss.size() - 1; i > 0; --i)
 {
        cv::Mat lap, upGauss;
        // 上采样操作
        cv::pyrUp(Gauss[i], upGauss);
        // 检查并调整尺寸
        if (upGauss.size() != Gauss[i - 1].size())
        {
            cv::resize(upGauss, upGauss, Gauss[i - 1].size());
        }
        // 计算拉普拉斯金字塔的当前层
        lap = Gauss[i - 1] - upGauss;
        Lap.push_back(lap);
    }
    // 显示高斯金字塔
    for (int i = 0; i < Gauss.size(); ++i)
    {
        std::string name = std::to_string(i);
        cv::imshow("G" + name, Gauss[i]);
    }
    // 显示拉普拉斯金字塔
    for (int i = 0; i < Lap.size(); ++i)
    {
        std::string name = std::to_string(i);
        cv::imshow("L" + name, Lap[i]);
    }

    cv::waitKey (0);

    return 0;
}
