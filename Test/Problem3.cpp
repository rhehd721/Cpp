#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(int N, std::vector<int> sequence) {
  int result(0);
	int Currently_Idx(0);

  vector<int> House(N);
  for(int i = 1; i <= N; i++){
    House[i-1] = i;
  }

  int Move_front(0);
  int Move_back(0);

  for(int i : sequence){
    Move_front = 0;
    Move_back = 0;
    if(House[Currently_Idx] >= i ){
      Move_front = (House.size() - 1) - Currently_Idx + (i - 1);
      Move_back = House[Currently_Idx] - i;
      if(Move_front >= Move_back){
        result += Move_back;
      }
      else{
        result += Move_front;
      }
    }
    else{
      Move_front = i - House[Currently_Idx];
      Move_back = ( Currently_Idx + 1 ) + (N - i);
      if(Move_front >= Move_back){

      }
      else{
        
      }
    }
  }



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
  std::cout << "Result: " << result_1  << std::endl;
  // Expected output: Result: 4

  // vector<int> sequence_2 = {3, 5, 4, 1, 2};
  vector<int> sequence_2;
  sequence_2.push_back(3);
  sequence_2.push_back(5);
  sequence_2.push_back(4);
  sequence_2.push_back(1);
  sequence_2.push_back(2);
  int result_2 = solution(num, sequence_2);
  std::cout << "Result: " << result_2  << std::endl;
  // Expected output: Result: 8

  return 0;
}