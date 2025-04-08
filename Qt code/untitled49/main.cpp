////////////////////////#include <opencv2/opencv.hpp>
////////////////////////
////////////////////////#include<vector>
////////////////////////using namespace cv;
////////////////////////using namespace std;
////////////////////////Mat frame, frame1, out;
////////////////////////int main()
////////////////////////{
////////////////////////    frame = imread("图片1.png");
////////////////////////    cvtColor(frame, frame1, COLOR_BGR2GRAY);
////////////////////////
////////////////////////    Scalar lower_green1(11, 43, 46), upper_green1(25, 255, 255);
////////////////////////    Scalar lower_green2(150, 43, 46), upper_green2(180, 255, 255);
////////////////////////
////////////////////////    Mat mask1, mask2;
////////////////////////    inRange(frame1, lower_green1, upper_green1, mask1);
////////////////////////    inRange(frame1, lower_green2, upper_green2, mask2);
////////////////////////    Mat mask = mask1 | mask2;
////////////////////////    imshow("2", mask);
////////////////////////
////////////////////////    GaussianBlur(mask, mask, Size(13, 13), 4, 4);
////////////////////////    threshold(mask, mask, 170, 255, THRESH_BINARY | THRESH_OTSU);
////////////////////////    vector<vector<Point>>contours;
////////////////////////    vector<Vec4i>woleogdou;
////////////////////////    findContours(mask, contours, woleogdou, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
////////////////////////    for (int t = 0; t < contours.size(); t++) {
////////////////////////        drawContours(frame, contours, t, Scalar(0, 0, 255), 2, 0);
////////////////////////    }
////////////////////////    for (int i = 0; i < woleogdou.size(); i++) {
////////////////////////        cout << woleogdou[i] << endl;
////////////////////////    }
////////////////////////    imshow("1", frame);
////////////////////////    //imwrite("图片1.png", frame);
////////////////////////    waitKey(0);
////////////////////////    return 0;
////////////////////////
////////////////////////
////////////////////////}
//////////////////////#include <opencv2/opencv.hpp>
//////////////////////#include <vector>
//////////////////////using namespace cv;
//////////////////////using namespace std;
//////////////////////
//////////////////////Mat frame, frameHSV, out;
//////////////////////
//////////////////////int main()
//////////////////////{
//////////////////////    // 读取图像
//////////////////////    frame = imread("图片4.png");
//////////////////////    if (frame.empty()) {
//////////////////////        cout << "无法读取图像，请检查文件路径！" << endl;
//////////////////////        return -1;
//////////////////////    }
//////////////////////
//////////////////////    // 将图像转换为HSV颜色空间
//////////////////////    cvtColor(frame, frameHSV, COLOR_BGR2HSV);
//////////////////////
//////////////////////    // 定义的HSV范围
//////////////////////    Scalar lower_green1(0, 43, 46), upper_green1(52, 29, 29);
//////////////////////    Scalar lower_green2(53, 29, 20), upper_green2(180, 255, 255);
//////////////////////
//////////////////////    // 创建掩膜
//////////////////////    Mat mask1, mask2;
//////////////////////    inRange(frameHSV, lower_green1, upper_green1, mask1);
//////////////////////    inRange(frameHSV, lower_green2, upper_green2, mask2);
//////////////////////    Mat mask = mask1 | mask2;
//////////////////////
//////////////////////    // 显示掩膜图像
//////////////////////    imshow("Mask", mask);
//////////////////////
//////////////////////    // 高斯模糊
//////////////////////    GaussianBlur(mask, mask, Size(13, 13), 4, 4);
//////////////////////
//////////////////////    // 阈值处理
//////////////////////    threshold(mask, mask, 0, 255, THRESH_BINARY | THRESH_OTSU);
//////////////////////
//////////////////////    // 查找轮廓
//////////////////////    vector<vector<Point>> contours;
//////////////////////    vector<Vec4i> woleogdou;
//////////////////////    findContours(mask, contours, woleogdou, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//////////////////////
//////////////////////    // 绘制轮廓
//////////////////////    for (int t = 0; t < contours.size(); t++) {
//////////////////////        drawContours(frame, contours, t, Scalar(0, 0, 255), 2, 0);
//////////////////////    }
//////////////////////
//////////////////////    // 输出轮廓层级信息
//////////////////////   /* for (int i = 0; i < woleogdou.size(); i++) {
//////////////////////        cout << woleogdou[i] << endl;
//////////////////////    }*/
//////////////////////
//////////////////////    // 显示绘制轮廓后的图像
//////////////////////    imshow("Contours", frame);
//////////////////////
//////////////////////    // 保存图像
//////////////////////    // imwrite("图片1.png", frame);
//////////////////////
//////////////////////    // 等待按键事件
//////////////////////    waitKey(0);
//////////////////////    return 0;
//////////////////////}
//////////////#include <opencv2/opencv.hpp>
//////////////#include <vector>
//////////////using namespace cv;
//////////////using namespace std;
//////////////
//////////////Mat frame, out;
//////////////
//////////////int main()
//////////////{
//////////////    // 读取图像
//////////////    frame = imread("f98a42c02465cc6c33b2f4db6901cc2a.jpeg");
//////////////    if (frame.empty()) {
//////////////        cout << "无法读取图像，请检查文件路径！" << endl;
//////////////        return -1;
//////////////    }
//////////////
//////////////    // 定义的 rgb 范围
//////////////    Scalar lower_green(0, 0, 120);  // 这里的 bgr 顺序，分量较高
//////////////    Scalar upper_green(100, 100, 255);
//////////////
//////////////    // 创建掩膜
//////////////    Mat mask;
//////////////    inrange(frame, lower_green, upper_green, mask);
//////////////
//////////////    // 显示掩膜图像
//////////////    imshow("mask", mask);
//////////////
//////////////    // 高斯模糊
//////////////    gaussianblur(mask, mask, size(13, 13), 4, 4);
//////////////
//////////////    // 阈值处理
//////////////    threshold(mask, mask, 0, 255, thresh_hsv | thresh_otsu);
//////////////
//////////////    // 查找轮廓
//////////////    vector<vector<point>> contours;
//////////////    vector<vec4i> woleogdou;
//////////////    Findcontours(mask, contours, woleogdou, retr_tree, chain_approx_simple, point());
//////////////
//////////////    // 绘制轮廓
//////////////    for (int t = 0; t < contours.size(); t++) {
//////////////        drawcontours(frame, contours, t, Scalar(0, 0, 255), 2, 0);
//////////////    }
//////////////
//////////////    // 输出轮廓层级信息
//////////////    /*for (int i = 0; i < woleogdou.size(); i++) {
//////////////        cout << woleogdou[i] << endl;
//////////////    }*/
//////////////
//////////////    // 显示绘制轮廓后的图像
//////////////    imshow("contours", frame);
//////////////
//////////////    // 保存图像
//////////////    // imwrite("图片1.png", frame);
//////////////
//////////////    // 等待按键事件
//////////////    waitkey(0);
//////////////    return 0;
//////////////}
////////////#include <opencv2/opencv.hpp>
////////////
////////////#include<vector>
////////////using namespace cv;
////////////using namespace std;
////////////Mat frame, frame1, out;
////////////int main()
////////////{
////////////    frame = imread("f98a42c02465cc6c33b2f4db6901cc2a.jpeg");
////////////    if (frame.empty())
////////////    {
////////////        cout << "q" << endl;
////////////        return -1;
////////////    }
////////////    cvtColor(frame, frame1, COLOR_BGR2GRAY);
////////////
////////////    Scalar lower_green1(11, 43, 46), upper_green1(25, 255, 255);
////////////    Scalar lower_green2(150, 43, 46), upper_green2(180, 255, 255);
////////////
////////////    Mat mask1, mask2;
////////////    inRange(frame1, lower_green1, upper_green1, mask1);
////////////    inRange(frame1, lower_green2, upper_green2, mask2);
////////////    Mat mask = mask1 | mask2;
////////////    imshow("2", mask);
////////////
////////////    GaussianBlur(mask, mask, Size(13, 13), 4, 4);
////////////    threshold(mask, mask, 170, 255, THRESH_BINARY | THRESH_OTSU);
////////////    vector<vector<Point>>contours;
////////////    vector<Vec4i>woleogdou;
////////////    findContours(mask, contours, woleogdou, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
////////////    for (int t = 0; t < contours.size(); t++) {
////////////        drawContours(frame, contours, t, Scalar(0, 0, 255), 2, 0);
////////////    }
////////////    for (int i = 0; i < woleogdou.size(); i++) {
////////////        cout << woleogdou[i] << endl;
////////////    }
////////////    imshow("1", frame);
////////////    //imwrite("图片1.png", frame);
////////////    waitKey(0);
////////////    return 0;
////////////
////////////
////////////}
//////////////#include <opencv2/opencv.hpp>
//////////////#include <iostream>
//////////////using namespace cv;
//////////////using namespace std;
//////////////
//////////////// 全局变量
//////////////Mat frame, frameHSV, mask;
//////////////int hmin = 0, smin = 0, vmin = 0;
//////////////int hmax = 180, smax = 255, vmax = 255;
//////////////
//////////////// 回调函数
//////////////void onTrackbar(int, void*) {
//////////////    Scalar lower(hmin, smin, vmin);
//////////////    Scalar upper(hmax, smax, vmax);
//////////////    inRange(frameHSV, lower, upper, mask);
//////////////    imshow("Mask", mask);
//////////////}
//////////////
//////////////int main() {
//////////////    // 读取图像
//////////////    frame = imread("f98a42c02465cc6c33b2f4db6901cc2a.jpeg");
//////////////    if (frame.empty()) {
//////////////        cout << "无法读取图像" << endl;
//////////////        return -1;
//////////////    }
//////////////
//////////////    // 转换为HSV颜色空间
//////////////    cvtColor(frame, frameHSV, COLOR_BGR2HSV);
//////////////
//////////////    // 创建窗口
//////////////    namedWindow("Mask", WINDOW_NORMAL);
//////////////
//////////////    // 创建滑动条
//////////////    createTrackbar("Hue Min", "Mask", &hmin, 180, onTrackbar);
//////////////    createTrackbar("Hue Max", "Mask", &hmax, 180, onTrackbar);
//////////////    createTrackbar("Sat Min", "Mask", &smin, 255, onTrackbar);
//////////////    createTrackbar("Sat Max", "Mask", &smax, 255, onTrackbar);
//////////////    createTrackbar("Val Min", "Mask", &vmin, 255, onTrackbar);
//////////////    createTrackbar("Val Max", "Mask", &vmax, 255, onTrackbar);
//////////////
//////////////    // 初始调用回调函数
//////////////    onTrackbar(0, 0);
//////////////
//////////////    // 等待按键
//////////////    waitKey(0);
//////////////
//////////////    return 0;
//////////////}
////////////////
////////////
//////////////#include <opencv2/opencv.hpp>
//////////////#include <iostream>
//////////////using namespace std;
//////////////using namespace cv;
//////////////
//////////////// 为了能在被调用函数中使用，设置成全局的
//////////////int value;
//////////////Mat frame1, frame2;
//////////////
//////////////// 回调函数，当滑动条值改变时调用
//////////////static void callback(int, void*)
//////////////{
//////////////    // 将滑动条的值转换为百分比
//////////////    float a = value / 100.0;
//////////////    // 调整图像亮度，通过乘以百分比实现
//////////////    frame2 = frame1 * a;
//////////////    // 显示调整亮度后的图像
//////////////    imshow("滑动条改变图像亮度", frame2);
//////////////}
//////////////
//////////////int main()
//////////////{
//////////////    // 读取图像
//////////////    frame1 = imread("lena.png");
//////////////    // 检查图像是否成功读取
//////////////    if (!frame1.data)
//////////////    {
//////////////        cout << "请确认是否输入正确的图像文件" << endl;
//////////////        return -1;
//////////////    }
//////////////    // 创建窗口
//////////////    namedWindow("滑动条改变图像亮度");
//////////////    // 显示原始图像
//////////////    imshow("滑动条改变图像亮度", frame1);
//////////////    // 滑动条创建时的初始值
//////////////    value = 100;
//////////////    // 创建滑动条
//////////////    createTrackbar("亮度值百分比", "滑动条改变图像亮度", &value, 600, callback, 0);
//////////////    // 等待按键事件
////////////////    waitKey(0);
////////////////    return 0;
////////////////}
////////////#include <opencv2/opencv.hpp>
////////////#include <iostream>
////////////
////////////using namespace std;
////////////using namespace cv;
////////////
//////////////为了能在被调用函数中使用，设置成全局的
////////////int value;
////////////void callBack(int, void*);  //滑动条回调函数
////////////Mat frame1, frame2;
////////////
////////////int main()
////////////{
////////////    frame1 = imread("lena.png");
////////////    if (!frame1.data)
////////////    {
////////////        cout << "请确认是否输入正确的图像文件" << endl;
////////////        return -1;
////////////    }
////////////    namedWindow("改变图像2亮度");
////////////    imshow("滑动条改变图2像亮度", frame1);
////////////    value = 100;  //滑动条创建时的初始值
////////////    //创建滑动条
////////////    createTrackbar("亮度值百分比", "滑动条改变图像亮度", &value, 600, callBack, 0);
////////////    waitKey();
////////////    return 0;
////////////}
////////////
////////////static void callBack(int, void*)
////////////{
////////////    float a = value / 100.0;
////////////    frame2 = frame1 * a;
////////////    imshow("滑动条改变图像亮度", frame2);
////////////}
////////////#include <opencv2/opencv.hpp>
////////////#include <iostream>
////////////
////////////using namespace cv;
////////////using namespace std;
////////////
////////////int main() {
////////////    // 读取用于方框滤波的图像
////////////    Mat equalLena = imread("lena.png", IMREAD_ANYDEPTH);
////////////    if (equalLena.empty()) {
////////////        cout << "请确认图像文件名是否正确" << endl;
////////////        return -1;
////////////    }
////////////
////////////    // 构建验证方框滤波算法的数据矩阵
////////////    float points[25] = { 1, 2, 3, 4, 5,
////////////                         6, 7, 8, 9, 10,
////////////                         11, 12, 13, 14, 15,
////////////                         16, 17, 18, 19, 20,
////////////                         21, 22, 23, 24, 25 };
////////////    Mat data(5, 5, CV_32FC1, points);
////////////
////////////    // 将图像类型转换为 CV_32F
////////////    Mat equalLena_32F;
////////////    equalLena.convertTo(equalLena_32F, CV_32F, 1.0 / 255);
////////////
////////////    Mat resultNorm, result, dataSqrNorm, dataSqr, equalLena_32FSqr;
////////////
////////////    // 方框滤波（归一化）
////////////    boxFilter(equalLena, resultNorm, -1, Size(3, 3), Point(-1, -1), true);
////////////    // 方框滤波（不归一化）
////////////    boxFilter(equalLena, result, -1, Size(3, 3), Point(-1, -1), false);
////////////
////////////    // 平方方框滤波（数据矩阵，归一化）
////////////    sqrBoxFilter(data, dataSqrNorm, -1, Size(3, 3), Point(-1, -1), true, BORDER_CONSTANT);
////////////    // 平方方框滤波（数据矩阵，不归一化）
////////////    sqrBoxFilter(data, dataSqr, -1, Size(3, 3), Point(-1, -1), false, BORDER_CONSTANT);
////////////    // 平方方框滤波（转换后的图像，归一化）
////////////    sqrBoxFilter(equalLena_32F, equalLena_32FSqr, -1, Size(3, 3), Point(-1, -1), true, BORDER_CONSTANT);
////////////
////////////    // 显示处理结果
////////////    imshow("resultNorm", resultNorm);
////////////    imshow("result", result);
////////////    imshow("equalLena_32FSqr", equalLena_32FSqr);
////////////    waitKey(0);
////////////    return 0;
////////////}
////////////#include <opencv2/opencv.hpp>
////////////#include <iostream>
////////////
////////////using namespace cv;
////////////using namespace std;
////////////
////////////int main() {
////////////    // 创建边缘检测滤波器
////////////    Mat kernel1 = (Mat_<float>(1, 2) << 1, -1); // X方向边缘检测滤波器
////////////    Mat kernel2 = (Mat_<float>(1, 3) << 1, 0, -1); // X方向边缘检测滤波器
////////////    Mat kernel3 = (Mat_<float>(3, 1) << 1, 0, -1); // X方向边缘检测滤波器
////////////    Mat kernelXY = (Mat_<float>(2, 2) << 1, 0, 0, -1); // 由左上到右下方边缘检测滤波器
////////////    Mat kernelYX = (Mat_<float>(2, 2) << 0, -1, 1, 0); // 由右上到左下方边缘检测滤波器
////////////
////////////    // 读取图像，黑白图像边缘检测结果较为明显
////////////    Mat frame = imread("1111.jpeg", IMREAD_ANYCOLOR);
////////////    if (frame.empty()) {
////////////        cout << "请确认图像文件名称是否正确" << endl;
////////////        return -1;
////////////    }
////////////    Mat result1, result2, result3, result4, result5, result6;
////////////
////////////    // 检测图像边缘
////////////    // 以[1 -1]检测水平方向边缘
////////////    filter2D(frame, result1, CV_16S, kernel1);
////////////    convertScaleAbs(result1, result1);
////////////
////////////    // 以[1 0 -1]检测水平方向边缘
////////////    filter2D(frame, result2, CV_16S, kernel2);
////////////    convertScaleAbs(result2, result2);
////////////
////////////    // 以[1 0 -1]检测垂直方向边缘
////////////    filter2D(frame, result3, CV_16S, kernel3);
////////////    convertScaleAbs(result3, result3);
////////////
////////////    // 整幅图像的边缘
////////////    result6 = result2 + result3;
////////////
////////////    // 检测由左上到右下方向边缘
////////////    filter2D(frame, result4, CV_16S, kernelXY);
////////////    convertScaleAbs(result4, result4);
////////////
////////////    // 检测由右上到左下方向边缘
////////////    filter2D(frame, result5, CV_16S, kernelYX);
////////////    convertScaleAbs(result5, result5);
////////////
////////////    // 显示边缘检测结果
////////////    imshow("result1", result1);
////////////    imshow("result2", result2);
////////////    imshow("result3", result3);
////////////    imshow("result4", result4);
////////////    imshow("result5", result5);
////////////    imshow("result6", result6);
////////////    waitKey(0);
////////////    return 0;
////////////}
////////////#include <opencv2\opencv.hpp>
////////////#include <iostream>
////////////
////////////using namespace cv;
////////////using namespace std;
////////////
////////////int main()
////////////{
////////////    //读取图像，黑白图像边缘检测结果较为明显
////////////    Mat frame = imread("lena.png", IMREAD_ANYCOLOR);
////////////    if (frame.empty())
////////////    {
////////////        cout << "请确认图像文件名称是否正确" << endl;
////////////        return -1;
////////////    }
////////////    Mat resultX, resultY, resultXY;
////////////
////////////    //X 方向一阶边缘
////////////    Sobel(frame, resultX, CV_16S, 2, 0, 1);
////////////    convertScaleAbs(resultX, resultX);
////////////
////////////    //Y 方向一阶边缘
////////////    Sobel(frame, resultY, CV_16S, 0, 1, 3);
////////////    convertScaleAbs(resultY, resultY);
////////////
////////////    //整幅图像的一阶边缘
////////////    resultXY = resultX | resultY;
////////////
////////////    //显示图像
////////////    imshow("frame", frame);
////////////    imshow("resultX", resultX);
////////////    imshow("resultY", resultY);
////////////    imshow("resultXY", resultXY);
////////////    waitKey(0);
////////////    return 0;
////////////}
////////////#include <opencv2\opencv.hpp>
////////////#include <iostream>
////////////
////////////using namespace cv;
////////////using namespace std;
////////////
////////////int main()
////////////{
////////////    //读取图像，黑白图像边缘检测结果较为明显
////////////    Mat frame = imread("1111.jpeg", IMREAD_ANYDEPTH);
////////////    if (frame.empty())
////////////    {
////////////        cout << "请确认图像文件名称是否正确" << endl;
////////////        return -1;
////////////    }
////////////    Mat resultX, resultY, resultXY;
////////////
////////////    //X 方向一阶边缘
////////////    Scharr(frame, resultX, CV_16S, 1, 0);
////////////    convertScaleAbs(resultX, resultX);
////////////
////////////    //Y 方向一阶边缘
////////////    Scharr(frame, resultY, CV_16S, 0, 1);
////////////    convertScaleAbs(resultY, resultY);
////////////
////////////    //整幅图像的一阶边缘
////////////    resultXY = resultX + resultY;
////////////
////////////    //显示图像
////////////    imshow("resultX", resultX);
////////////    imshow("resultY", resultY);
////////////    imshow("resultXY", resultXY);
////////////    waitKey(0);
////////////    return 0;
////////////}
////////////#include <opencv2/opencv.hpp>
////////////#include <iostream>
////////////
////////////using namespace cv;
////////////using namespace std;
////////////
////////////int main() {
////////////    // 读取图像
////////////    Mat rice = imread("车牌(SU7).jpg", IMREAD_GRAYSCALE);
////////////    imshow("rice", rice);
////////////    if (rice.empty()) {
////////////        cout << "请确认图像文件名称是否正确" << endl;
////////////        return -1;
////////////    }
////////////
////////////    // 构建简易矩阵，用于求取像素之间的距离
////////////    Mat a = (Mat_<uchar>(5, 5) << 1, 1, 1, 1, 1,
////////////        1, 1, 1, 1, 1,
////////////        1, 1, 0, 1, 1,
////////////        1, 1, 1, 1, 1,
////////////        1, 1, 1, 1, 1);
////////////    Mat dist_L1, dist_L2, dist_C;
////////////
////////////    // 计算街区距离（城市街区距离，类型1）
////////////    distanceTransform(a, dist_L1, DIST_L1, 3, CV_8U);
////////////    cout << "街区距离：\n" << dist_L1 << endl;
////////////
////////////    // 计算欧氏距离（类型2）
////////////    distanceTransform(a, dist_L2, DIST_L2, 5, CV_8U);
////////////    cout << "欧氏距离：\n" << dist_L2 << endl;
////////////
////////////    // 计算棋盘距离（类型3）
////////////    distanceTransform(a, dist_C, DIST_C, 5, CV_8U);
////////////    cout << "棋盘距离：\n" << dist_C << endl;
////////////
////////////    // 处理目标图像：二值化与反色
////////////    Mat riceBW, riceBW_INV;
////////////    threshold(rice, riceBW, 175, 255, THRESH_BINARY);
////////////    threshold(rice, riceBW_INV, 175, 255, THRESH_BINARY_INV);
////////////    imshow("riceBW", riceBW);
////////////    // 对反色图像进行距离变换
////////////    Mat dist_INV;
////////////    distanceTransform(riceBW_INV, dist_INV, DIST_C, 3, CV_8U);
////////////
////////////    // 显示结果
////////////    imshow("riceBW_INV", riceBW_INV);
////////////    imshow("dist_INV", dist_INV);
////////////    waitKey(0);
////////////    return 0;
////////////}
//////////#include <opencv2/opencv.hpp>
//////////#include <iostream>
//////////#include <vector>
//////////
//////////using namespace cv;
//////////using namespace std;
//////////
//////////int main() {
//////////    // 读取图像
//////////    Mat frame = imread("车牌(SU7).jpg");
//////////    if (frame.empty()) {
//////////        cout << "请确认图像文件名称是否正确" << endl;
//////////        return -1;
//////////    }
//////////
//////////    Mat rice, riceBW;
//////////    // 转换为灰度图
//////////    cvtColor(frame, rice, COLOR_BGR2GRAY);
//////////    // 二值化处理
//////////    threshold(rice, riceBW, 50, 255, THRESH_BINARY);
//////////
//////////    // 生成随机颜色，用于区分不同连通域
//////////    RNG rng(10086);
//////////    Mat out;
//////////    // 统计图像中连通域的个数，8邻域，CV_16U输出标签
//////////    int number = connectedComponents(riceBW, out, 8, CV_16U);
//////////    vector<Vec3b> colors;
//////////    for (int i = 0; i < number; i++) {
//////////        // 生成随机颜色（BGR格式）
//////////        Vec3b vec3 = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
//////////        colors.push_back(vec3);
//////////    }
//////////
//////////    // 以不同颜色标记不同的连通域
//////////    Mat result = Mat::zeros(rice.size(), frame.type());
//////////    int w = result.cols;
//////////    int h = result.rows;
//////////    for (int row = 0; row < h; row++) {
//////////        for (int col = 0; col < w; col++) {
//////////            uint16_t label = out.at<uint16_t>(row, col);
//////////            if (label == 0)  // 背景的黑色不改变
//////////                continue;
//////////            result.at<Vec3b>(row, col) = colors[label];
//////////        }
//////////    }
//////////
////////////    // 显示结果
////////////    imshow("原图", frame);
////////////    imshow("标记后的图像", result);
////////////    waitKey(0);
////////////    return 0;
////////////}
//////////#include <opencv2/opencv.hpp>
//////////#include <iostream>
//////////#include <vector>
//////////
//////////using namespace cv;
//////////using namespace std;
//////////
//////////int main() {
//////////   // system("color FA"); // 修改输出界面颜色
//////////    // 对图像进行距离变换
//////////    Mat frame = imread("816cfa8a320a11082ee2d08b59fb7be6.jpg");
//////////    if (frame.empty()) {
//////////        cout << "请确认图像文件名称是否正确" << endl;
//////////        return -1;
//////////    }
//////////
//////////    Mat rice, riceBW;
//////////    // 将图像转成二值图像，用于统计连通域
//////////    cvtColor(frame, rice, COLOR_BGR2GRAY);
//////////    threshold(rice, riceBW, 50, 255, THRESH_BINARY);
//////////
//////////    // 生成随机颜色，用于区分不同连通域
//////////    RNG rng(10086);
//////////    Mat out, stats, centroids;
//////////    // 统计图像中连通域，获取统计信息
//////////    int number = connectedComponentsWithStats(
//////////        riceBW, out, stats, centroids, 8, CV_16U
//////////    );
//////////
//////////    vector<Vec3b> colors;
//////////    for (int i = 0; i < number; i++) {
//////////        // 使用均匀分布的随机数确定颜色
//////////        Vec3b vec3 = Vec3b(
//////////            rng.uniform(0, 256),
//////////            rng.uniform(0, 256),
//////////            rng.uniform(0, 256)
//////////        );
//////////        colors.push_back(vec3);
//////////    }
//////////
//////////    // 以不同颜色标记不同的连通域
//////////    Mat result = Mat::zeros(rice.size(), frame.type());
//////////    int w = result.cols;
//////////    int h = result.rows;
//////////    for (int row = 0; row < h; row++) {
//////////        for (int col = 0; col < w; col++) {
//////////            uint16_t label = out.at<uint16_t>(row, col);
//////////            if (label == 0)  // 背景不改变
//////////                continue;
//////////            result.at<Vec3b>(row, col) = colors[label];
//////////        }
//////////    }
//////////
//////////    // 标记连通域信息（中心、外接矩形、面积）
//////////    for (int i = 1; i < number; i++) {
//////////        // 中心位置
//////////        int center_x = centroids.at<double>(i, 0);
//////////        int center_y = centroids.at<double>(i, 1);
//////////
//////////        // 矩形参数
//////////        int x = stats.at<int>(i, CC_STAT_LEFT);
//////////        int y = stats.at<int>(i, CC_STAT_TOP);
//////////        int w = stats.at<int>(i, CC_STAT_WIDTH);
//////////        int h = stats.at<int>(i, CC_STAT_HEIGHT);
//////////
//////////        // 面积
//////////        int area = stats.at<int>(i, CC_STAT_AREA);
//////////
//////////        // 中心位置绘制
//////////        circle(result, Point(center_x, center_y), 2, Scalar(0, 255, 0), 2, 8, 0);
//////////        // 外接矩形
//////////        Rect rect(x, y, w, h);
//////////        rectangle(frame, rect, colors[i], 1, 8, 0);
//////////        // 显示面积
//////////        putText(frame,cv::forMat("Area: %d", area),
//////////            Point(center_x - 15, center_y + 15),
//////////            FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 1), 1);
//////////        cout << "number: " << i << ", area: " << area << endl;
//////////    }
////////////
////////////    // 显示结果
////////////    imshow("标记后的图像", result);
////////////    imshow("原图标记结果", frame);
////////////    waitKey(0);
////////////    return 0;
////////////}
//////////#include <opencv2/opencv.hpp>
//////////#include <iostream>
//////////#include <vector>
//////////
//////////using namespace cv;
//////////using namespace std;
//////////
//////////int main()
//////////{
//////////    // 生成用于膨胀的原图
//////////    Mat src = Mat::Mat(cv::Size(6, 6), CV_8U, Scalar(0));
//////////    Mat src2 = Mat::Mat(cv::Size(6, 6), CV_8U, Scalar(255));
//////////
//////////    // 矩形结构元素
//////////    Mat struct1 = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
//////////    // 十字结构元素
//////////    Mat struct2 = getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));
//////////
//////////    Mat erodeSrc;  // 存储腐蚀后的图像
//////////    Mat dilateSrc; // 存储膨胀后的图像
//////////
//////////    namedWindow("src", WINDOW_GUI_NORMAL);
//////////    namedWindow("erodeSrc", WINDOW_GUI_NORMAL);
//////////    namedWindow("dilateSrc", WINDOW_GUI_NORMAL);
//////////
//////////    imshow("src", src);
//////////
//////////    // 膨胀操作
//////////    dilate(src, dilateSrc, struct1);
//////////    dilate(src, dilateSrc, struct2);
//////////    dilate(src2, dilateSrc, struct1);
//////////    dilate(src2, dilateSrc, struct2);
//////////
//////////    imshow("dilate_black1", dilateSrc);
//////////    imshow("dilate_black2", dilateSrc);
//////////    imshow("dilate_white1", dilateSrc);
//////////    imshow("dilate_white2", dilateSrc);
//////////
//////////    // 腐蚀与膨胀的逻辑运算
//////////    Mat erode_black1, resultXor, resultAnd;
//////////    Mat erode_white1, resultOr, resultNand;
//////////
//////////    erode(LearnCV_black, erode_black1, struct1);
//////////    bitwise_xor(erode_black1, dilate_black1, resultXor);
//////////    bitwise_and(erode_black1, dilate_black1, resultAnd);
//////////
//////////    erode(LearnCV_white, erode_white1, struct1);
//////////    bitwise_or(erode_white1, dilate_white1, resultOr);
//////////    bitwise_nand(erode_white1, dilate_white1, resultNand);
//////////
//////////    imshow("resultXor", resultXor);
//////////    imshow("resultAnd", resultAnd);
//////////    imshow("resultOr", resultOr);
//////////    imshow("resultNand", resultNand);
//////////
//////////    waitKey(0);
//////////    return 0;
//////////}
//////////#include <opencv2/opencv.hpp>
//////////#include <iostream>
//////////using namespace cv;
//////////using namespace std;
//////////
//////////int main() {
//////////    // 生成用于膨胀的原图
//////////    Mat src = (Mat_<uchar>(6, 6) << 0, 0, 0, 0, 255, 0,
//////////        0, 255, 255, 255, 255, 0,
//////////        0, 255, 255, 255, 255, 0,
//////////        0, 255, 255, 255, 255, 0,
//////////        0, 255, 255, 255, 255, 0,
//////////        0, 0, 0, 0, 0, 0);
//////////    Mat struct1 = getStructuringElement(0, Size(3, 3)); // 矩形结构元素
//////////    Mat struct2 = getStructuringElement(1, Size(3, 3)); // 十字结构元素
//////////
//////////    Mat erodeSrc; // 存放腐蚀后的图像
//////////    dilate(src, erodeSrc, struct2); // 此处代码逻辑存疑，dilate用于膨胀，erode才是腐蚀
//////////
//////////    namedWindow("src", WINDOW_GUI_NORMAL);
//////////    namedWindow("dilateSrc", WINDOW_GUI_NORMAL);
//////////    imshow("src", src);
//////////    imshow("dilateSrc", erodeSrc);
//////////
//////////    Mat LearnCV_black = imread("PixPin_2025-03-07_15-24-29.png", IMREAD_ANYCOLOR);
//////////   // Mat LearnCV_white = imread("816cfa8a320a11082ee2d08b59fb7be6.jpg", IMREAD_ANYCOLOR);
//////////    /*if (LearnCV_black.empty() || LearnCV_white.empty()) {
//////////        cout << "请确认图像文件名称是否正确" << endl;
//////////        return -1;
//////////    }*/
//////////
//////////    Mat dilate_black1, dilate_black2, dilate_write1, dilate_write2;
//////////    // 黑色背景图像膨胀
//////////    dilate(LearnCV_black, dilate_black1, struct1);
//////////    dilate(LearnCV_black, dilate_black2, struct2);
//////////    imshow("LearnCV_black", LearnCV_black);
//////////    imshow("dilate_black1", dilate_black1);
//////////    imshow("dilate_black2", dilate_black2);
//////////
//////////    // 白色背景图像膨胀
//////////   /* dilate(LearnCV_white, dilate_write1, struct1);
//////////    dilate(LearnCV_white, dilate_write2, struct2);
//////////    imshow("LearnCV_white", LearnCV_white);
//////////    imshow("dilate_write1", dilate_write1);
//////////    imshow("dilate_write2", dilate_write2);*/
//////////
//////////    // 比较膨胀和腐蚀的结果
//////////    Mat erode_black1, resultXor, resultAnd;
//////////    erode(LearnCV_black, erode_black1, struct1);
//////////    bitwise_xor(erode_black1, dilate_write1, resultXor);
//////////    //bitwise_and(erode_black1, dilate_write1, resultAnd);
//////////    imshow("resultXor", resultXor);
//////////    //imshow("resultAnd", resultAnd);
//////////
//////////    waitKey(0);
//////////    return 0;
//////////}
////////
//////////#include <iostream>
//////////
//////////#include <opencv2/ xframeproc.hpp>
//////////#include <opencv2/opencv.hpp>
//////////using namespace cv;
//////////using namespace std;
//////////
//////////int main()
//////////{
//////////    //对中文字符进行细化
//////////    Mat frame = imread("LearnCV_black.png", IMREAD_ANYCOLOR);
//////////    if (frame.empty())
//////////    {
//////////        cout << "请确认图像文件名称是否正确" << endl;
//////////        return -1;
//////////    }
//////////    //对英文字符、实心圆和圆环进行细化
//////////    Mat words = Mat::zeros(100, 200, CV_8UC1);  //创建一个黑色的背景图片
//////////    putText(words, "Learn", Point(30, 30), 2, 1, Scalar(255), 2);  //添加英文字符
//////////    putText(words, "OpenCV 4", Point(30, 60), 2, 1, Scalar(255), 2);
//////////    circle(words, Point(80, 75), 10, Scalar(255), -1);  //添加实心圆
//////////    circle(words, Point(130, 75), 10, Scalar(255), 3);  //添加圆环
//////////
//////////    //进行细化
//////////    Mat thin1, thin2;
//////////    xframeproc::thinning(frame, thin1, 0);  //注意类名
//////////    xframeproc::thinning(words, thin2, 0);
//////////
//////////    //显示处理结果
//////////    imshow("thin1", thin1);
//////////    imshow("frame", frame);
//////////		namedWindow("thin2", WINDOW_NORMAL);
//////////    imshow("thin2", thin2);
//////////    namedWindow("words", WINDOW_NORMAL);
//////////    imshow("words", words);
//////////    waitKey(0);
//////////    return 0;
//////////}
////////#include <opencv2/opencv.hpp>
////////#include <iostream>
////////
////////using namespace cv;
////////using namespace std;
////////
////////// 自定义比较函数，用于排序轮廓
////////bool compareContourArea(vector<Point> contour1, vector<Point> contour2) {
////////    double area1 = contourArea(contour1);
////////    double area2 = contourArea(contour2);
////////    return (area1 > area2);
////////}
////////
////////int main() {
////////    // 打开摄像头
////////    VideoCapture cap(0);
////////    if (!cap.isOpened()) {
////////        cout << "Error: Failed to open camera." << endl;
////////        return -1;
////////    }
////////
////////    while (true) {
////////        Mat frame;
////////        cap >> frame; // 从摄像头中获取一帧图像
////////
////////        // 检查是否成功获取了图像
////////        if (frame.empty()) {
////////            cout << "Error: Failed to capture frame." << endl;
////////            break;
////////        }
////////
////////        // 将图像转换为灰度图
////////        Mat gray;
////////        cvtColor(frame, gray, COLOR_BGR2GRAY);
////////
////////        // 对灰度图进行阈值处理，分割出绿色色块
////////        Mat green_hsv;
////////        inRange(frame, Scalar(0, 100, 0), Scalar(100, 255, 100), green_hsv); // 绿色色块的阈值范围
////////
////////        // 寻找绿色色块的轮廓
////////        vector<vector<Point>> green_contours;
////////        findContours(green_hsv, green_contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
////////
////////        // 对轮廓按面积进行排序
////////        sort(green_contours.begin(), green_contours.end(), compareContourArea);
////////
////////        // 仅保留最大的两个绿色色块
////////        vector<Point> largest_green_contour;
////////        if (green_contours.size() >= 1) {
////////            largest_green_contour = green_contours[0];
////////        }
////////
////////        // 计算最大绿色色块的中心和坐标
////////        Moments green_moments = moments(largest_green_contour);
////////        Point green_center(green_moments.m10 / green_moments.m00, green_moments.m01 / green_moments.m00);
////////
////////        // 在图像上绘制最大绿色色块的中心和坐标
////////        circle(frame, green_center, 5, Scalar(0, 255, 0), -1);
////////
////////        // 获取最大绿色色块的边界框
////////        Rect green_bbox = boundingRect(largest_green_contour);
////////
////////        // 在图像上框出最大绿色色块的轮廓
////////        rectangle(frame, green_bbox, Scalar(0, 255, 0), 2);
////////
////////        // 显示处理后的图像
////////        imshow("Frame", frame);
////////
////////        // 检查是否按下了ESC键，如果按下则退出循环
////////        if (waitKey(30) == 27) {
////////            break;
////////        }
////////    }
////////
////////    // 关闭摄像头
////////    cap.release();
////////    destroyAllWindows();
////////
////////    return 0;
////////}
//视觉识别
#include <opencv2/opencv.hpp>
#include <iostream>
#include<vector>
using namespace cv;
using namespace std;

//轮廓排序
//bool compareContourArea(vector<Point> contour1, vector<Point> contour2) {
//    double area1 = contourArea(contour1);
//    double area2 = contourArea(contour2);
//    return (area1 > area2);
//}

int main()
{
    // 打开摄像头
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Error: Failed to open camera." << endl;
        return -1;
    }
    while (true)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty()) {
            cout << "Error: Failed to capture frame." << endl;

            break;
        }
        //imshow("原图", frame);
        Mat _hsv;
        cvtColor(frame, _hsv, COLOR_BGR2HSV);
        //blur(hsv, hsv, Size(3, 3));
        GaussianBlur(_hsv, _hsv, Size(5, 5), 0);
        Mat lower_hue_range;
        Mat upper_hue_range;
        inRange(_hsv, Scalar(156, 40, 50), Scalar(180, 255, 255), lower_hue_range);
        inRange(_hsv, Scalar(100, 43, 46), Scalar(124, 255, 255), upper_hue_range);
        // 合并掩码
        Mat hsv;
        bitwise_or(lower_hue_range, upper_hue_range, hsv);
        imshow("hsv", hsv);
        // 色块轮廓
        vector<vector<Point>> _contours;
        findContours(hsv, _contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        // 排序
        if (!_contours.empty())
        {
            int maxIndex = 0;
            double maxArea = contourArea(_contours[0]);

            // 遍历所有轮廓
            for (int i = 1; i < _contours.size(); i++) {
                double area = contourArea(_contours[i]);
                if (area > maxArea) {
                    maxArea = area;
                    maxIndex = static_cast<int>(i);
                }
            }
            // 计算矩形
            RotatedRect rect = minAreaRect(_contours[maxIndex]);
            Point2f points[4];
            rect.points(points);
            Point2f cpt = rect.center;
            // 绘制矩形
            for (int i = 0; i < 4; i++)
            {
                line(frame, points[i], points[(i + 1) % 4], Scalar(0, 255, 0), 2);
            }
            // 绘制矩形中心点
            circle(frame, cpt, 5, Scalar(0, 0, 255), -1);
        }            
            imshow("Frame", frame);
            if (waitKey(30) == 27){
                break;\
            }
    }    
    cap.release();
    return 0;
  
    
}
//        //结束
////5555555
//////#include <opencv2/opencv.hpp>
//////#include <iostream>
//////
//////using namespace cv;
//////using namespace std;
//////
//////// 自定义比较函数，用于排序轮廓
//////bool compareContourArea(vector<Point> contour1, vector<Point> contour2) {
//////    double area1 = contourArea(contour1);
//////    double area2 = contourArea(contour2);
//////    return (area1 > area2);
//////}
//////
//////int main() {
//////    VideoCapture cap(0);
//////    if (!cap.isOpened()) {
//////        cout << "Error: Failed to open camera." << endl;
//////        return -1;
//////    }
//////
//////    while (true) {
//////        Mat frame;
//////        cap >> frame;
//////        if (frame.empty()) {
//////            cout << "Error: Failed to capture frame." << endl;
//////            break;
//////        }
//////
//////        // 转换为HSV颜色空间
//////        Mat hsv;
//////        cvtColor(frame, hsv, COLOR_BGR2HSV);
//////
//////        // 检测所有高饱和度和高亮度的区域（通用色块检测）
//////        Mat hsv_mask;
//////        inRange(hsv, Scalar(0, 50, 50), Scalar(180, 255, 255), hsv_mask);
//////
//////        // 寻找轮廓
//////        vector<vector<Point>> contours;
//////        findContours(hsv_mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//////
//////        // 按面积排序
//////        sort(contours.begin(), contours.end(), compareContourArea);
//////
//////        // 处理最大的色块
//////        if (!contours.empty()) {
//////            vector<Point> largest_contour = contours[0];
//////
//////            // 计算质心
//////            Moments moments = moments(largest_contour);
//////            if (moments.m00 != 0) {
//////                Point center(moments.m10 / moments.m00, moments.m01 / moments.m00);
//////                circle(frame, center, 5, Scalar(0, 255, 0), -1);
//////            }
//////
//////            // 绘制边界框
//////            Rect bbox = boundingRect(largest_contour);
//////            rectangle(frame, bbox, Scalar(0, 255, 0), 2);
//////        }
//////
//////        imshow("Frame", frame);
//////        if (waitKey(30) == 27) break;
//////    }
//////
//////    cap.release();
//////    destroyAllWindows();
//////    return 0;
//////}
//// 保留色块
//        //vector<Point> largest_contour;
//        //if (_contours.size() >= 1) {
//        //    largest_contour = _contours[0];
//        //}
//
//        //Rect _bbox = boundingRect(largest_contour);
//        //// 框出的轮廓
//        // rectangle(frame, _bbox, Scalar(0, 0, 255), 2);
////#include <stdio.h>
////
////int main() {
////    int i, j, k;
////    printf("请输入三个数i,j,k:\n");
////    scanf_s("%d %d %d", &i, &j, &k);
////    (((i % 2 == 0) ? 1 : 0) + ((j % 2 == 0) ? 1 : 0) + ((k % 2 == 0) ? 1 : 0)) == 2? printf("YES\n") : printf("NO\n");
////    return 0;
////}
//
////#include <opencv2/opencv.hpp>
////#include <iostream>
////#include <vector>
////
////using namespace cv;
////using namespace std;
////
////int main()
////{
////     VideoCapture cap(2);
////     if (!cap.isOpened()) {
////         cout << "Error: Failed to open camera." << endl;
////         return -1;
////     }
////     while (true)
////     {
////         Mat frame;
////         cap >> frame;
////         if (frame.empty()) {
////             cout << "Error: Failed to capture frame." << endl;
////
////             break;
////         }
////     
////
////    // 二值化
////    Mat gray, binary;
////    cvtColor(frame, gray, COLOR_BGR2GRAY);
////    threshold(gray, binary, 105, 255, THRESH_BINARY);
////
////    //开运算消除细小区域
////    Mat k = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
////    morphologyEx(binary, binary, MORPH_OPEN, k);
////    imshow("binary", binary);
////
////    // 轮廓发现
////    vector<vector<Point>> contours;
////    vector<Vec4i> hierarchy;
////    findContours(binary, contours, hierarchy, 0, 2, Point());
////    for (int n = 0; n < contours.size(); n++)
////    {
////        //计算凸包
////        vector<Point> hull;
////        convexHull(contours[n], hull);
////        //绘制凸包
////        for (int i = 0; i < hull.size(); i++)
////        {
////            //绘制凸包顶点
////            circle(frame, hull[i], 4, Scalar(255, 0, 0), 2, 8, 0);
////
////            //连接凸包
////            if (i == hull.size() - 1)
////            {
////                line(frame, hull[i], hull[0], Scalar(0, 0, 255), 2, 8, 0);
////                break;
////            }
////            line(frame, hull[i], hull[i + 1], Scalar(0, 0, 255), 2, 8, 0);
////        }
////    }
////    
////     imshow("hull", frame);
////     if (waitKey(30) == 27)
////     {
////         break;
////     }
////    }
////    waitKey(0);
////    return 0;
////}
//#include "opencv2/core.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
//
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//    Mat mat_src = Mat::eye(3, 4, CV_8UC1);
//
//    cout << "mat_src :" << endl;
//    cout << mat_src << endl;
//
//    cout << endl;
//    cout << "Rows : " << mat_src.rows << endl;
//    cout << "Cols : " << mat_src.cols << endl;
//
//    //注: mat_src.at<float>(y, x), 下标关系为: y-x
//    mat_src.at<int>(0, 2) = 2;
//    mat_src.at<int>(2, 0) = 4;
//
//    cout << endl;
//    cout << "mat_src :" << endl;
//    cout << mat_src << endl;
//
//    return 0;
//}