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

float CalculateIoU(Box b1, Box b2){ 
  float result(0);

  int X_min(0);
  int X_max(0);

  int Y_min(0);
  int Y_max(0);

  if(b1.left_ >= b2.left_){
    X_min = b2.left_;
  }
  else{
    X_min = b1.left_;
  }

  if(b1.right_ >= b2.right_){
    X_max = b1.right_;
  }
  else{
    X_max = b2.right_;
  }

  if(b1.top_ >= b2.top_){
    Y_min = b2.top_;
  }
  else{
    Y_min = b1.top_;
  }

  if(b1.bottom_ >= b2.bottom_){
    Y_max = b1.bottom_;
  }
  else{
    Y_max = b2.bottom_;
  }

  int width = X_max - X_min;
  int height = Y_max - Y_min;

  int Square[height][width];

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      Square[i][j] = 0;
    }
  }

  for(int i = b1.top_; i < b1.bottom_; i++){
    for(int j = b1.left_; j < b1.right_; j++){
      Square[i][j] = -1;
    }
  }

  for(int i = b2.top_; i < b2.bottom_; i++){
    for(int j = b2.left_; j < b2.right_; j++){
      if( Square[i][j] == -1){
        Square[i][j] = -2;
      }
      else{
        Square[i][j] = -1;
      }
    }
  }

  int num_two(0);
  int num_one(0);
  int num_zero(0);

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(Square[i][j] == 0){
        num_zero++;
      }
      else if(Square[i][j] == -1){
        num_one++;
      }
      else{
        num_two++;
      }
    }
  }

  if(num_two == 0){
    return 0;
  }
  else if(num_two != 0 && num_one == 0){
    return 1;
  }
  else{
    return ( (float)num_two / (float)(num_two + num_one));
  }

}

int main() {
  Box b1 = {0, 100, 0, 100};
  Box b2 = {0, 50, 0, 100};
  float iou_1 = CalculateIoU(b1, b2);
  cout << "IoU: " << iou_1 << endl;   // 0.5

  Box b3 = {50, 150, 0, 100};
  Box b4 = {0, 100, 0, 100};
  float iou_2 = CalculateIoU(b3, b4);
  cout << "IoU: " << iou_2 << endl;   // 0.333333

  Box b5 = {50, 150, 0, 100};
  Box b6 = {0, 50, 0, 100};
  float iou_3 = CalculateIoU(b5, b6);
  cout << "IoU: " << iou_3 << endl;   // 0

  Box b7 = {0, 50, 0, 100};
  Box b8 = {0, 50, 0, 100};
  float iou_4 = CalculateIoU(b7, b8);
  cout << "IoU: " << iou_4 << endl;   // 1

  Box b9 = {0, 100, 0, 100};
  Box b10 = {50, 150, 0, 100};
  float iou_5 = CalculateIoU(b9, b10);
  cout << "IoU: " << iou_5 << endl;   // 0.333333

	return 0;
}