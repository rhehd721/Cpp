// 제한사항
// 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
// 각 숫자는 1 이상 50 이하인 자연수입니다.
// 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> // 제곱을 사용하기 위한 라이브러리

using namespace std;

// int return_Num(int index, ){

// }


int solution(vector<int> numbers, int target) {
    int answer = 0;

    int Pluse(1);
    int Minuse(-1);

    int MaxNum = pow(2, numbers.size());
    vector<int> MakeNum(MaxNum);

    for(int index(0); index < numbers.size(); index++){



    }
    
    
    cout << answer << endl;
    return answer;
}

int main(){
    vector<int> numbers(5, 1);
    int	target(3);

    solution(numbers, target);	// return 5
}