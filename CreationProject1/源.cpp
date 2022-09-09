#include <opencv2/opencv.hpp>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc.hpp>  
#include<opencv2/objdetect.hpp>
#include<iostream> 
using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("D:/Creation/recourse/3.jpg");

    CascadeClassifier faceCascade;//级联器
    faceCascade.load("D:\\Creation\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");//haar
    if (faceCascade.empty()) { cout << "XML 文件打开失败" << endl; }

    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.03, 10);
    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
    }
    imshow("Windows 11", img);
    waitKey(0);

    return 0;
}