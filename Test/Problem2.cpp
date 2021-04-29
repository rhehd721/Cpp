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

float CalculateIoU();

int num_TP(0), num_FN(0), num_FP(0);

void EvaluatePredictions(vector<Box>& prediction, vector<Box>& truth, const float iou, int &num_T, int &num_FN, int &num_FP) {
  num_T = 3;
}

int main(){
  Box test;

  EvaluatePredictions(test,test)
}