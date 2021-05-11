// 제한사항
// 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
// 각 숫자는 1 이상 50 이하인 자연수입니다.
// 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

#include <iostream>
#include <vector>

using namespace std;

int return_Num(int index, int num, int Max_Size, vector<int> & numbers, int & answer, int target);
int solution(vector<int> numbers, int target);

int return_Num(int index, int num, int Max_Size, vector<int> & numbers, int & answer, int target){// 현재 index, 현재까지 더한 수, 종결조건
    if(index == Max_Size){
        if(num == target){answer++;}
        return 0;
    }
    else{
        return_Num(index + 1, (num + numbers[index]), numbers.size(), numbers, answer, target);
        return_Num(index + 1, (num - numbers[index]), numbers.size(), numbers, answer, target);
    }
}


int solution(vector<int> numbers, int target) {
    int answer = 0;

    return_Num(0, 0, numbers.size(), numbers, answer, target);
    
    cout << answer << endl;
    return answer;
}

int main(){
    vector<int> numbers(5, 1);
    int	target(3);

    solution(numbers, target);	// return 5
}