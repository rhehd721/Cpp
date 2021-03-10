// 1 ~ 25 까지 지그재그로 출력하는 코드

#include <iostream>

using namespace std;

int main(){

    int num(25);

    for (int i = 1; i <= 25; i++){
        cout << i << "  ";
        if ((i % 5) == 0 ){
            cout << endl;   // 5개 출력 후 줄바꿈
            for (int j = i + 5; j != i; j--){
                cout << j << "  ";
            }
            i += 5;
            cout << endl;
        }
    }
}