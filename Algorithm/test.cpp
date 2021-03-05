// 제한 사항
// scoville의 길이는 2 이상 1,000,000 이하입니다.
// K는 0 이상 1,000,000,000 이하입니다.
// scoville의 원소는 각각 0 이상 1,000,000 이하입니다.
// 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return 합니다.

// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;

  int NewScoville = 0;

  cout << scoville.size() << endl;

  for (int i : scoville){
    cout << i << "   ";
  }

  cout << endl;

  NewScoville = scoville[0] + ( scoville[1] * 2 );    // 새로만든 스코빌 지수
  scoville.erase(scoville.begin(), scoville.begin() + 2); // 합성에 사용된 음식 삭제
  scoville.push_back(NewScoville);    // 새로운 음식 추가

  cout << scoville.size() << endl;

  for (int i : scoville){
    cout << i << "   ";
  }

  cout << endl;

  cout << answer << endl;
  return answer;
}

int main(){
    vector<int> scoville;

    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    int K = 7;

    solution(scoville, K);   // 2
}