#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Box {
public:
  int left_;
  int right_;
  int top_;
  int bottom_;
};

float CalculateIoU(Box b1, Box b2){ // IoU = (B1 ∩ B2) / (B1 ∪ B2)
    float result(1);

    if(b1.right_ > b2.left_){   // x 좌표가 서로 겹치는지

    }
    else if(b2.left_){

    }





    return result;
}

int main() {
    Box b1 = {0, 100, 0, 100};
    Box b2 = {0, 50, 0, 100};
    float iou_1 = CalculateIoU(b1, b2);
    std::cout << "IoU: " << iou_1 << std::endl;   // 0.5

    Box b3 = {50, 150, 0, 100};
    Box b4 = {0, 100, 0, 100};
    float iou_2 = CalculateIoU(b3, b4);
    std::cout << "IoU: " << iou_2 << std::endl;   // 0.333333

    Box b5 = {50, 150, 0, 100};
    Box b6 = {0, 50, 0, 100};
    float iou_3 = CalculateIoU(b5, b6);
    std::cout << "IoU: " << iou_3 << std::endl;   // 0

    Box b7 = {0, 50, 0, 100};
    Box b8 = {0, 50, 0, 100};
    float iou_4 = CalculateIoU(b7, b8);
    std::cout << "IoU: " << iou_4 << std::endl;   // 1

    Box b9 = {0, 100, 0, 100};
    Box b10 = {50, 150, 0, 100};
    float iou_5 = CalculateIoU(b9, b10);
    std::cout << "IoU: " << iou_5 << std::endl;   // 0.333333

	return 0;
}

