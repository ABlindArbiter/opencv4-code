#include <opencv2/opencv.hpp>

int main()
{
    uchar lutFirst[256];
    for (int i = 0; i < 256; i++)
    {
        if (i < 100)
        {
            lutFirst[i] = 0;
        }
        if (i > 100 && i <= 200)
        {
            lutFirst[i] = 100;
        }
        if (i > 200)
        {
            lutFirst[i] = 255;
        }
    }
    cv::Mat lutOne(1, 256, CV_8UC1, lutFirst);

    uchar lutSecond[256];
    for (int i = 0; i < 256; i++)
    {
        if (i < 100)
        {
            lutSecond[i] = 0;
        }
        if (i > 100 && i <= 200)
        {
            lutSecond[i] = 100;
        }
        if (i > 200)
        {
            lutSecond[i] = 255;
        }
    }
    cv::Mat lutTwo(1, 256, CV_8UC1, lutSecond);

    uchar lutThird[256];
    for (int i = 0; i < 256; i++)
    {
        if (i < 100)
        {
            lutThird[i] = 0;
        }
        if (i > 100 && i <= 200)
        {
            lutThird[i] = 100;
        }
        if (i > 200)
        {
            lutThird[i] = 255;
        }
    }
    cv::Mat lutThree(1, 256, CV_8UC1, lutThird);

    std::vector<cv::Mat> mergeMats;
    mergeMats.push_back(lutOne);
    mergeMats.push_back(lutTwo);
    mergeMats.push_back(lutThree);
    cv::Mat LutTree;
    merge(mergeMats, LutTree);

    cv::Mat img = cv::imread("1.jpeg");
    cv::Mat gray, out0, out1, out2;
    cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::LUT(gray, lutOne, out0);
    cv::LUT(img, lutTwo, out1);
    cv::LUT(img, lutThree, out2);
    imshow("out0", out0);
    imshow("out1", out1);
    imshow("out2", out2);

    cv::waitKey(0);

    return 0;
}
