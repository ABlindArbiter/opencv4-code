#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    system("color F0");//error.
    cv::VideoCapture video("火柴人.mp4");
    if (video.isOpened())
    {
        std::cout << "宽度：" << video.get(cv::CAP_PROP_FRAME_WIDTH) <<std::endl;
        std::cout << "高度：" << video.get(cv::CAP_PROP_FRAME_HEIGHT) <<std::endl;
        std::cout << "帧率：" << video.get(cv::CAP_PROP_FPS) <<std::endl;
        std::cout << "总帧数：" << video.get(cv::CAP_PROP_FRAME_COUNT) <<std::endl;
    }
    else
    {
        std::cout << "没开成功" << std::endl;
        return -1;
    }
    while(1)
    {
        cv::Mat frame;
        video >> frame;
        if (frame.empty())
        {
            break;
        }
        //cv::namedWindow("video", cv::WINDOW_FREERATIO);//缩放怎么无效了？
        imshow("video", frame);
        cv::waitKey(1000 / video.get(cv::CAP_PROP_FPS));//帧与帧之间合适的间隔时间：1000/帧率
    }
    cv::waitKey();

    return 0;
}
