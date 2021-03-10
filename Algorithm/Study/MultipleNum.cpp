// 임의의 숫자 N에 대하여 특정 범위에서 N의 배수의 갯수와 그들의 합을 구해주는 코드

#include <iostream>
#include <vector>

using namespace std;

void inputNum(int &num);

int main(){
    cout << "\n\n0 ~ 1000이하 임의의 숫자 N에 대하여 배수의 갯수와 합을 구하는 프로그램\n" << endl;

    int num(0);
    inputNum(num);

    cout << "\n선택하신 숫자는 " << num << "입니다!" << endl;

    int cnt(1);
    int multiple(num);

    vector<int> multipleList;

    while(1){
        if(multiple > 1000){
            break;
        }
        multipleList.push_back(multiple);
        multiple = num * ++cnt;
    }

    int sum(0);

    for (int i : multipleList){
        sum += i;
    }

    cout << num << "의 배수 : " << cnt - 1 << endl;
    cout << num << "의 배수의 합: " << sum << endl;
    

}

void inputNum(int &num){
    cout << "\n원하는 숫자를 입력하세요 : ";
    cin >> num;
    if (num > 1000 || num < 1){
        cout << "\nerror" << endl;
        inputNum(num);
    }
}