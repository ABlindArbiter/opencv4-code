#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat img;
    cv::VideoCapture vedio(0);

    if (!vedio.isOpened())
    {
        std::cout << "打开失败" << std::endl;
        return -1;
    }

    vedio >> img;
    if (img.empty())
    {
        std::cout << "未读取到 "<< std::endl;
        return -1;
    }
    bool isColor = (img.type() == CV_8UC3);

    cv::VideoWriter writer;
    int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');

    double fps = 25.0;
    std::string filename = "live.avi";
    writer.open(filename, codec, fps, img.size(), isColor);

    if (!writer.isOpened())//这里或许有点奇怪哈。
    {
        std::cout << "打开视频失败" << std::endl;
        return -1;
    }

    while(1)
    {
        if (!vedio.read(img))
        {
            std::cout << "断开连接或执行完成" << std::endl;
            break;
        }
        writer.write(img);
        writer << img;//不理解
        cv::imshow ("Live", img);//不显示是什么意思呢……
        char c = cv::waitKey(50);
        if (c == 27)
        {
            break;
        }
    }
    vedio.release();
    writer.release();

    return 0;
}
