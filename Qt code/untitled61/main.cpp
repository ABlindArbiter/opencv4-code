#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void drawLine(Mat &img,
               vector<Vec2f> lines,
               double rows,
               double cols,
               Scalar scalar,
               int n)
{
    Point pt1, pt2;
    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0];
        float theta = lines[i][1];
        double a = cos(theta);
        double b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        double length = max(rows, cols);

        //计算直线上的一点
        pt1.x = cvRound(x0 + length * (-b));
        pt1.y = cvRound(y0 + length * (a));
        //计算形状一侧另一点
        pt2.x = cvRound(x0 - length * (-b));
        pt2.y = cvRound(y0 - length * (a));

        //两点绘制一条直线
        line(img, pt1, pt2, scalar, n);
    }
}

int main() {
    Mat img = imread("11.jpeg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cout << "请确认图像文件名称是否正确" << endl;
        return -1;
    }
    Mat edge;

    //检测边缘图像并二值化
    Canny(img, edge, 80, 180, 3, false);
    threshold(edge, edge, 170, 255, THRESH_BINARY);

    //用不同的累加器检测直线
    vector<Vec2f> lines1, lines2;
    HoughLines(edge, lines1, 1, CV_PI / 180, 150, 0, 0);
    HoughLines(edge, lines2, 1, CV_PI / 180, 150, 0, 0);

    //在原图像中绘制直线
    Mat img1, img2;
    img.copyTo(img1);
    img.copyTo(img2);
    drawLine(img1, lines1, edge.rows, edge.cols, Scalar(255), 2);
    drawLine(img2, lines2, edge.rows, edge.cols, Scalar(255), 2);

    //显示图像
    imshow("edge", edge);
    imshow("img1", img1);
    imshow("img2", img2);

    waitKey(0);

    return 0;
}
