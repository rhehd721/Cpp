#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat src, dst, src_gray;

int main(){
	
    int rtn(0);

    src = imread("../Image/test.jpeg");
    cout << "test" << endl;

    cvtColor(src, src_gray, COLOR_RGB2GRAY);
    imshow("imgGRAY", src_gray);

    rtn = waitKey(0);
    if(rtn == 27){
        return 0;
    }

    return 0;

}