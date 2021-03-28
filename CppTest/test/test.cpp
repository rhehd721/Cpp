////
////  test.cpp
////  CppTest
////
////  Created by 알파카 on 2021/01/15.
////
//
//#include <iostream>
//
//using namespace std;
//
//int n;
//
//void set(){
//    ::n = 10;
//}
//
//namespace pbh {
//    int n;
//    void set(){
//        pbh::n = 20;
//    }
//}
//namespace google {
//    int n;
//    void set(){
//        google::n = 30;
//    }
//}
//
//int main(){
//    std::cout << "hello world" << std::endl;
//
//    ::set();
//    pbh::set();
//    google::set();
//
//    cout << ::n << endl;
//    cout << pbh::n << endl;
//    cout << google::n << endl;
//}

//# include <iostream>
//
//using namespace std;
//
//struct TV{
//    bool powerOn;
//    int channal;
//    int volume;
//
//    void setVolume(int vol){
//        if(vol >= 0 && vol <=100){
//            volume = vol;
//        }
//    }
//};
//
//int main(){
//    TV lg;
//    lg.powerOn = true;
//    lg.channal = 10;
//    lg.volume = 40;
//    lg.setVolume(50);
//
//}

// #include <iostream>

// using namespace std;

// class Time{
// public:
//     Time() : h(0), m(0), s(0) {}
//     Time(int s_) : Time() {
//         s = s_;
//     }
//     Time(int m_, int s_) : Time(s_) {
//         m = m_;
//     }
//     Time(int h_, int m_, int s_) : Time(m_, s_) {
//         h = h_;
//     }
    
// //private:
//     int h = 0;
//     int m = 0;
//     int s = 0;
    
// };

// int main(){
//     Time t(7, 5, 16);
    
//     cout << t.h << ":" << t.m << ":" << t.s << endl;
    
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    int start(0);
    int end(0);

    string str1 = "TEST";
    string str2 = "ES";
    
    // start = str1.find(str2);
    // end = (str1.find(str2)) + (str2.size()-1);
    // cout << start << endl;
    // cout << end << endl;
    // str1.replace(start, end, "");

    // cout << stoi("22");


    start = str1.find(str2 + "%");
    end = (str1.find(str2)) + (str2.size());
    // str1.replace(start,  "");

    cout << str1 << endl;
}