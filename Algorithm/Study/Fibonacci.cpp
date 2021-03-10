// 피보나치 수열
// f(n) = f(n-1) + f(n-2)

#include <iostream>

using namespace std;

int main(){

    cout << "\n\n\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << "hello world!" << endl << "피보나치 수열을 구해주는 프로그램 입니다!" << endl << "원히는 갯수를 입력해주세요 : ";

    int i = 0;
    int num = 0;
    
    int value_1 = 1;
    int value_2 = 0;
    int value_new;

    cin >> num;

    cout << num << "개의 피보나치 수 : ";


    while(i < num){
        value_new = value_1 + value_2;

        cout << value_new << "  ";

        value_2 = value_1;
        value_1 = value_new;
        i++;
    }

    cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n";
}