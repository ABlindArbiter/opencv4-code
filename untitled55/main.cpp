#include <opencv2/opencv.hpp>
#include <vector>

int main()
{
    //对图像进行距离变换
    cv::Mat img = cv::imread("12.jpg");
    cv::Mat rice, riceBW;

    //将图像转成二值图像，用于统计连通域
    cvtColor(img, rice, cv::COLOR_BGR2GRAY);
    threshold(rice, riceBW, 50, 255, cv::THRESH_BINARY);

    //生成随机颜色，用于区分不同连通域
    cv::RNG rng(10086);
    cv::Mat out;
    int number = connectedComponents(riceBW, out, 8, CV_16U);  //统计图像中连通域的个数
    std::vector<cv::Vec3b> colors;
    for (int i = 0; i < number; i++)
    {
        //使用均匀分布的随机数确定颜色
        cv::Vec3b vec(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
        colors.push_back(vec);
    }

    //用不同颜色标记不同的连通域
    cv::Mat result = cv::Mat::zeros(rice.size(), img.type());
    int h = result.rows;
    int w = result.cols;
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            int label = out.at<ushort>(row, col);
            if (label == 0)  //背景的颜色不改变
                continue;
            result.at<cv::Vec3b>(row, col) = colors[label];
        }
    }

    //显示结果
    imshow("原图", img);
    imshow("标记后的图像", result);

    cv::waitKey(0);

    return 0;
}
