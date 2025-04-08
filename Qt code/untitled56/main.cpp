#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int main()
{
    system("color F0"); //更改输出界面颜色
    //对图像进行读取变换
    cv::Mat img = cv::imread("12.jpg");
    imshow("原图", img);
    cv::Mat rimg, rimg2;

    //将图像转成二值图像，用于统计连通域
    cvtColor(img, rimg, cv::COLOR_BGR2GRAY);
    threshold(rimg, rimg2, 128, 255, cv::THRESH_BINARY);

    //获取轮廓颜色，用于区分不同连通域
    cv::RNG rng(12345);
    cv::Mat out, stats, centroids;

    //统计图像中连通域的数目
    int number = connectedComponentsWithStats(rimg2, out, stats, centroids, 8, CV_32S);

    std::vector<cv::Vec3b> colors;
    for (int i = 0; i < number; i++)
    {
        //使用均匀分布的随机数确定颜色
        cv::Vec3b vec = cv::Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
        colors.push_back(vec);
    }

    //以下用颜色标记不同的连通域
    cv::Mat result = cv::Mat::zeros(rimg.size(), img.type());
    int w = result.cols;
    int h = result.rows;
    for (int i = 0; i < number; i++)
    {
        // 中心位置
        int center_x = centroids.at<double>(i, 0);
        int center_y = centroids.at<double>(i, 1);
        //矩形边框
        int x = stats.at<int>(i, cv::CC_STAT_LEFT);
        int y = stats.at<int>(i, cv::CC_STAT_TOP);
        int width = stats.at<int>(i, cv::CC_STAT_WIDTH);
        int height = stats.at<int>(i, cv::CC_STAT_HEIGHT);
        // 中心位置绘制
        circle(result, cv::Point(center_x, center_y), 2, cv::Scalar(0, 255, 0), 2, 8, 0);
        // 外接矩形
        cv::Rect rect(x, y, width, height);
        rectangle(result, rect, colors[i], 1, 8, 0);
        putText(result, cv::format("%d", i), cv::Point(center_x, center_y), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
        std::cout << "连通域 " << i << " 中心: " << center_x << ", " << center_y << " area: " << width * height << std::endl;
    }
    //显示结果
    imshow("标记后的图像", result);

    cv::waitKey(0);

    return 0;
}
