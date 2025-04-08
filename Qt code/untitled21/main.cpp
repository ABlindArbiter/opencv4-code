#include <opencv2/opencv.hpp>
#include <vector>

int main()
{
    cv::Mat img = cv::imread("1.jpeg");
    //不同颜色，可调节窗口大小
    cv::Mat gray, HSV, YUV, Lab, img32;
    img.convertTo(img32, CV_32F, 1.0 / 255);

    cv::cvtColor(img32, HSV, cv::COLOR_BGR2HSV);
    cv::cvtColor(img32, YUV, cv::COLOR_BGR2YUV);
    cv::cvtColor(img32, Lab, cv::COLOR_BGR2Lab);
    cv::cvtColor(img32, gray, cv::COLOR_BGR2GRAY);

    cv::namedWindow("原图", cv::WINDOW_FREERATIO);
    cv::namedWindow("HSV", cv::WINDOW_FREERATIO);
    cv::namedWindow("YUV", cv::WINDOW_FREERATIO);
    cv::namedWindow("Lab", cv::WINDOW_FREERATIO);
    cv::namedWindow("gray", cv::WINDOW_FREERATIO);

    cv::imshow("原图", img32);
    cv::imshow("HSV", img32);
    cv::imshow("YUV", YUV);
    cv::imshow("Lab", Lab);
    cv::imshow("gray", gray);

    //二值化
    cv::Mat img_B, img_B_V, gray_B, gray_B_V, gray_T, gray_T_V, gray_TRUNC;

    threshold(img, img_B, 125, 255, cv::THRESH_BINARY);
    threshold(img, img_B_V, 125, 255, cv::THRESH_BINARY_INV);
    imshow("img_B", img_B);
    imshow("img_B_V", img_B_V);

    threshold(gray, gray_B, 125, 255, cv::THRESH_BINARY);
    threshold(gray, gray_B_V, 125, 255, cv::THRESH_BINARY_INV);
    imshow("gray_B", gray_B);
    imshow("gray_B_V", gray_B_V);

    threshold(gray, gray_T, 125, 255, cv::THRESH_TOZERO);
    threshold(gray, gray_T_V, 125, 255, cv::THRESH_TOZERO_INV);
    imshow("gray_T", gray_T);
    imshow("gray_T_V", gray_T_V);

    threshold(gray, gray_TRUNC, 125, 255, cv::THRESH_TRUNC);
    imshow("gray_TRUNC", gray_TRUNC);

    //查找映射
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

    cv::Mat out0, out1, out2;
    cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::LUT(gray, lutOne, out0);
    cv::LUT(img, lutTwo, out1);
    cv::LUT(img, lutThree, out2);
    imshow("out0", out0);
    imshow("out1", out1);
    imshow("out2", out2);

    //缩放
    cv::Mat smallImg, bigImg0, bigImg1, bigImg2;
    cv::resize(gray, smallImg, cv::Size(15, 15), 0, 0, cv::INTER_AREA);
    cv::resize(smallImg, bigImg0, cv::Size(30, 30), 0, 0, cv::INTER_NEAREST);
    cv::resize(smallImg,bigImg1, cv::Size(30, 30), 0, 0, cv::INTER_LINEAR);
    cv::resize(smallImg, bigImg2, cv::Size(30, 30), 0, 0, cv::INTER_CUBIC);
    cv::namedWindow("smallImg", cv::WINDOW_NORMAL);
    imshow("smallImg", smallImg);
    cv::namedWindow("bigImg0", cv::WINDOW_NORMAL);
    imshow("bigImg0", bigImg0);
    cv::namedWindow("bigImg1", cv::WINDOW_NORMAL);
    imshow("bigImg1", bigImg1);
    cv::namedWindow("bigImg2", cv::WINDOW_NORMAL);
    imshow("bigImg2", bigImg2);

    //翻转
    cv::Mat img_x, img_y, img_xy;
    flip(img, img_x, 0);
    flip(img, img_y, 1);
    flip(img, img_xy, -1);
    imshow("x", img_x);
    imshow("y", img_y);
    imshow("xy", img_xy);

    //仿射变换
    cv::Mat rotation0, rotation1, img_warp0, img_warp1;
    double angle = 30;
    cv::Size dst_size(img.rows, img.cols);
    cv::Point2f center(img.rows / 2.0, img.cols / 2.0);
    rotation0 = getRotationMatrix2D (center, angle, 1);
    cv::warpAffine(img, img_warp0, rotation0, dst_size);
    imshow("img_warp0", img_warp0);

    cv::Point2f src_points[3];
    cv::Point2f dst_points[3];
    src_points[0] = cv::Point2f(0, 0);
    src_points[1] = cv::Point2f(0, (float)(img.cols - 1));
    src_points[2] = cv::Point2f((float)(img.rows - 1), (float)(img.cols - 1));

    dst_points[0] = cv::Point2f((float)(img.rows) * 0.11, (float)(img.cols) * 0.20);
    dst_points[1] = cv::Point2f((float)(img.rows) * 0.15, (float)(img.cols) * 0.70);
    dst_points[2] = cv::Point2f((float)(img.rows) * 0.81, (float)(img.cols) * 0.85);
    rotation1 = cv::getAffineTransform(src_points, dst_points);
    warpAffine(img, img_warp1, rotation1, dst_size);
    imshow("img_warp1", img_warp1);

    //添加文字图形
    cv::circle(img, cv::Point(50, 50), 25, cv::Scalar(255, 255, 255), -1);
    cv::circle(img, cv::Point(100, 50), 20, cv::Scalar(255, 255, 255), 4);

    cv::line(img, cv::Point(100, 100), cv::Point(200, 100), cv::Scalar(255, 255, 255), 2, cv::LINE_4, 0);

    cv::ellipse(img, cv::Point(300, 255), cv::Size(100, 70), 0, 0, 100, cv::Scalar(255, 255, 255), -1);
    cv::ellipse(img, cv::RotatedRect(cv::Point2f(150, 100), cv::Size2f(30, 20), 0), cv::Scalar(0, 0, 255), 2);
    std::vector<cv::Point> points;

    cv::ellipse2Poly(cv::Point(200, 400), cv::Size(100, 70), 0, 0, 360, 2, points);
    for (int i = 0; i < points.size() - 1; i++)
    {
        if (i == points.size() - 1)
        {
            cv::line(img, points[0], points[1], cv::Scalar(255, 255, 255), 2);
            break;
        }
        cv::line(img, points[1], points[i + 1], cv::Scalar(255, 255, 255), 2);
    }

    cv::rectangle(img, cv::Point(50, 400), cv::Point(100, 450), cv::Scalar(125, 125, 125), -1);
    cv::rectangle(img, cv::Rect(400, 450, 60, 50), cv::Scalar(0, 125, 125), 2);

    cv::Point pp[2][6];
    pp[0][0] = cv::Point(72, 200);
    pp[0][1] = cv::Point(142, 204);
    pp[0][2] = cv::Point(226, 273);
    pp[0][3] = cv::Point(172, 310);
    pp[0][4] = cv::Point(117, 340);
    pp[0][5] = cv::Point(30, 260);
    pp[1][0] = cv::Point(359, 339);
    pp[1][1] = cv::Point(447, 341);
    pp[1][2] = cv::Point(504, 349);
    pp[1][3] = cv::Point(414, 433);
    pp[1][4] = cv::Point(418, 449);
    pp[1][5] = cv::Point(354, 451);
    cv::Point pp2[5];
    pp2[0] = cv::Point(350, 83);
    pp2[1] = cv::Point(463, 90);
    pp2[2] = cv::Point(500, 171);
    pp2[3] = cv::Point(421, 194);
    pp2[4] = cv::Point(338, 141);
    const cv::Point *pts[3] = {pp[0], pp[1], pp[2]};
    int npts[] = {6, 6, 5};
    fillPoly(img, pts, npts, 3, cv::Scalar(125, 125, 125), 0);

    cv::putText(img, "123123123", cv::Point(400, 400), 2, 1, cv::Scalar(255, 255, 255));
    imshow("img", img);

    cv::waitKey(0);

    return 0;
}
