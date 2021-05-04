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
    Tree * first;
    Tree * second;
    int num;
}Tree;

Tree* Make_Tree(Tree * Parent, int child){
    Tree * Plus_node = new Tree;
    Plus_node -> num = child;

    Tree * Minus_node = new Tree;
    Plus_node -> num = (-1 * child);

    return Plus_node;
    // return Plus_node, Minus_node;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int result(0);

    Tree * Start = new Tree;
    Start -> num = 0;

    for(int num : numbers){
        Start = Make_Tree(Start, num);
        
    }

    // if(result == target){
    //     answer++;
    // }
        
    cout << "answer : " << answer << endl;
    return answer;
}

int main(){
    vector<int> numbers(5, 1);
    int	target(3);

    solution(numbers, target);	// return 5
}