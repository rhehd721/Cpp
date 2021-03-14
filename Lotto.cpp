// // 심심해서 만드는 로또

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int MakeRandomNum();
vector<int> MakeWinningNumList();

int main(){    

    vector<int> WinningNumList;

    WinningNumList = MakeWinningNumList();
    
    cout << "\n로또 당첨번호 : ";

    for (int i : WinningNumList){
        cout << "  " << i;
    }

    cout << endl << endl;

    return 0;
}

vector<int> MakeWinningNumList(){
    vector<int> WinningNumList;
    int LuckNum(0);
    bool check(0);

    while(1){
        LuckNum = MakeRandomNum();
        for(int i : WinningNumList){
            if (LuckNum == i){
                check = 1;
                break;
            }
        }
        if(check){
            check = 0;
            continue;
        }
        else{
            WinningNumList.push_back(LuckNum);
            if(WinningNumList.size() == 6){
                break;
            }
        }
    }
    sort(WinningNumList.begin(), WinningNumList.end());
    return WinningNumList;
}

int MakeRandomNum(){
    // 시드값을 얻기 위한 random_device 생성.
    random_device RandomNum;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    mt19937 Reset(RandomNum());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    uniform_int_distribution<int> Num(1, 45);
    
    return Num(Reset);
}