// 미완성

// 제한사항
// 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
// 각 숫자는 1 이상 50 이하인 자연수입니다.
// 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Tree{
    Tree * left;
    Tree * right;
    int data;
}Tree;

Tree * MakeTree(vector<int> num, int size){
    Tree * ptr = new Tree;
    ptr -> data = 0;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    Tree * root = MakeTree(numbers, target);
    
    cout << answer << endl;
    return answer;
}

int main(){
    vector<int> numbers(5, 1);
    int	target(3);

    solution(numbers, target);	// return 5
}