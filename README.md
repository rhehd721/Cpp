# C++

## Library
``` cpp
#include <iostream> // c언어에서 stdio.h


``` 
---
## namespace
``` cpp
using namespace + <namespace>; // 코드에서 사용할 namespace를 미리 알려주여 namespace 생략 가능


``` 
---

## 함수명 중복
``` cpp
#include <iostream>

void drawRectangle(int l, int r, int t, int b){
    
}

void drawRectangle(int w, int h, int x =0){
    
}

int main(){
    drawRectangle(1,2,3,4);
    drawRectangle(1,2,3);
}
```
위 코드와 같이 함수명이 중복될 수 있으나 매개변수의 개수가 달라야 하며 default parameter가 마지막에 존재해야 한다.

---

## private, public
``` cpp
// 전역으로 사용
public:
    int a;
    int b;
// 지역으로 사용
private:
    int c;
    int d;
``` 
struct의 경우 private, public 모두 써주어야 하지만
class의 경우 자동으로 private상황을 만들어주어 public만 입력해주면 된다.

---

## this
``` cpp
#include <iostream>

using namespace std;

class MyClass{
    void PrintThis(){
        cout << "나의 주소는" << this << endl;
    }
};

int main(){
    MyClass a,b
    
    cout << "a의 주소는" << &a << endl;
    cout << "b의 주소는" << &b << endl;

    a.PrintThis();
    b.PrintThis();
}
``` 
this는 자신이 소속되어 있는 객체의 주솟값을 받는다.

모든 class나 struct 안에 멤버 함수들은 보이지 않는 매개변수(*this)를 가지고 있다.

---

## 생성자, 소멸자
``` cpp
class MyClass{
public:
    // MyClass(){ // 생성자
    //     real = 0;
    //     imag = 0;
    // }

    MyClass() : real(0), imag(0) {}

    void SetReal(double real_){
        real = real_;
    }
    void GetImage(){
        retuen imag;
    }

    ~MyClass(){
        // 소멸자
    }
private:
    double real;
    double imag;
};
``` 
생성자와 소멸자는 객체가 생성되고 소멸될 때 각각 나타난다.

생성자 : 멤버 변수의 초기화에 사용(오버로딩 가능)

* 응용

``` cpp
#include <iostream>

using namespace std;

class Time{
public:
    Time() : h(0), m(0), s(0) {}
    Time(int s_) : Time() {
        s = s_;
    }
    Time(int m_, int s_) : Time(s_) {
        m = m_;
    }
    Time(int h_, int m_, int s_) : Time(m_, s_) {
        h = h_;
    }
    
//private:
    int h = 0;
    int m = 0;
    int s = 0;
    
};

int main(){
    Time t(7, 5, 16);
    
    cout << t.h << ":" << t.m << ":" << t.s << endl;
    
    return 0;
}
``` 

---