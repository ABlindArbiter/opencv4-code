#include <opencv2/opencv.hpp>

//椒盐噪声函数
void saltAndPepper(cv::Mat image, int n)
{
    for (int k = 0; k<n / 2; k++)
    {
        //随机确定图像中位置
        int i, j;
        i = std::rand() % image.cols;  //取余数运算，保证在图像的列数内
        j = std::rand() % image.rows;  //取余数运算，保证在图像的行数内
        int white_black = std::rand() % 2;  //判定是白色噪声还是黑色噪声的变量//生成随机二进制
        if (white_black == 0)  //添加白色噪声
        {
            if (image.type() == CV_8UC1)  //处理灰度图像
            {
                image.at<uchar>(j, i) = 255;  //白色噪声
            }
            else if (image.type() == CV_8UC3)  //处理彩色图像
            {
                image.at<cv::Vec3b>(j, i)[0] = 255;  //Vec3b为OpenCV定义的3个值的向量类型
                image.at<cv::Vec3b>(j, i)[1] = 255;  //[1]指定通道，B:0，G:1，R:2
                image.at<cv::Vec3b>(j, i)[2] = 255;
            }
        }
        else  //添加黑色噪声
        {
            if (image.type() == CV_8UC1)
            {
                image.at<uchar>(j, i) = 0;
            }
            else if (image.type() == CV_8UC3)
            {
                image.at<cv::Vec3b>(j, i)[0] = 0;  //Vec3b为OpenCV定义的3个值的向量类型
                image.at<cv::Vec3b>(j, i)[1] = 0;  //[1]指定通道，B:0，G:1，R:2
                image.at<cv::Vec3b>(j, i)[2] = 0;
            }
        }
    }
}

int main()
{
    cv::Mat lena = cv::imread("1.jpeg");
    cv::Mat equilena = cv::imread("2.jpeg", cv::IMREAD_ANYDEPTH);
    imshow("1原图", lena);
    imshow("2原图", equilena);
    saltAndPepper(lena, 10000);  //彩色图像添加椒盐噪声
    saltAndPepper(equilena, 5000);  //灰度图像添加椒盐噪声
    imshow("lena添加噪声", lena);
    imshow("equilena添加噪声", equilena);

    cv::waitKey(0);

    return 0;
}
