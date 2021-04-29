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

float CalculateIoU(Box b1, Box b2);

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

int num_TP(0), num_FN(0), num_FP(0);

void EvaluatePredictions(vector<Box>& prediction, // 예측 값
vector<Box>& truth, // 실제 값
const float iou, // 임계치
int &num_TP, int &num_FN, int &num_FP) {

  float io;

  for(int i = 0; i < prediction.size(); i++){
    io = CalculateIoU(prediction[i], truth[i]);
    if(io >= iou){
      num_TP++;
    }
    else{
      num_FN++;
      num_FP++;
    }
    
  }
  
}

int main(){
  Box b1 = {0, 100, 0, 100};
  Box b2 = {0, 50, 0, 100};
  float iou = CalculateIoU(b1, b2);

  
  

  
}