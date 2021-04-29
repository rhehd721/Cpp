#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(int N, vector<int> sequence) {
  int result(0);
  int Currently_Idx(0);

  int Move_front(0);
  int Move_back(0);

  int index = N-1;

  for (int i : sequence){
    int target_idx = i - 1;
    if(target_idx >= Currently_Idx){
      Move_front = target_idx - Currently_Idx;
      Move_back = Currently_Idx + ( index - target_idx ) + 1;
    }
    else{
      Move_front = ( index - Currently_Idx + 1) + target_idx;
      Move_back = Currently_Idx - target_idx;
    }

    cout << "Move : " << Move_front << ", " << Move_back << endl;

    if(Move_front > Move_back){
      result += Move_back;
    }
    else{
      result += Move_front;
    }
    Currently_Idx = target_idx;
  }

  
  return result;

}

int main() {
  const int num = 5;

  // vector<int> sequence_1 = {1, 2, 3, 4, 5};
  vector<int> sequence_1;
  sequence_1.push_back(1);
  sequence_1.push_back(2);
  sequence_1.push_back(3);
  sequence_1.push_back(4);
  sequence_1.push_back(5);
  int result_1 = solution(num, sequence_1);
  cout << "Result: " << result_1  << endl;
  // Expected output: Result: 4

  // vector<int> sequence_2 = {3, 5, 4, 1, 2};
  vector<int> sequence_2;
  sequence_2.push_back(3);
  sequence_2.push_back(5);
  sequence_2.push_back(4);
  sequence_2.push_back(1);
  sequence_2.push_back(2);
  int result_2 = solution(num, sequence_2);
  cout << "Result: " << result_2  << endl;
  // Expected output: Result: 8

  return 0;
}