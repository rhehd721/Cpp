// 어떤수 n에 대하여 약수를 구하는 코드

#include <iostream>

using namespace std;

int main(){

    cout << "\n\n\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "hello world!" << endl << "약수를 구해주는 프로그램 입니다!" << endl << "원히는 숫자를 입력해주세요 : ";

    int num;

    cin >> num;

    cout << num << "의 약수 : ";

    for (int i =1; i < num; i++){
        if((num % i) == 0){
            cout << i << "  ";
        }
    }     

    cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n";
}