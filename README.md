# C++

## 기본용어
메소드(method) == 멤버 함수(member function)

[Algorithm](https://github.com/rhehd721/Cpp/tree/master/Algorithm)

## Library
``` cpp
#include <iostream> // c언어에서 stdio.h
#include <string> // 문자열을 사용하게 해주는 라이
``` 
---
## namespace
``` cpp
using namespace + <namespace>; // 코드에서 사용할 namespace를 미리 알려주여 namespace 생략 가능
``` 
Ex
``` cpp
using namespace std;
``` 
---

## 함수명 중복(Overload)
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
위 코드와 같이 함수명이 중복될 수 있으나 매개변수의 타입 or 갯수가 달라야 하며 default parameter는 마지막에 존재해야 한다.


---

## private, public
캡슐화를 이용하여 사용자가 내부에 접근하는것을 막는다.
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
Class안 멤버함수 Class Object 마다 메모리에 할당되는것이 아닌 

대표로 하나의 메모리만이 할당된다 그렇기 때문에 보이지않는 포인터 

this를 이용하여 주솟값을 받아온다.

this는 자신이 소속되어 있는 객체의 주솟값을 받는다.
``` cpp
#include <iostream>

using namespace std;

class MyClass{
public:
    void PrintThis(){
        cout << "나의 주소는" << this << endl;
    }
};

int main(){
    MyClass a,b;
    
    cout << "a의 주소는" << &a << endl;
    cout << "b의 주소는" << &b << endl;

    a.PrintThis();
    b.PrintThis();
}
// a의 주소는0x7ffeefbff488
// b의 주소는0x7ffeefbff480
// 나의 주소는0x7ffeefbff488
// 나의 주소는0x7ffeefbff480
``` 

모든 class나 struct 안에 멤버 함수들은 보이지 않는 매개변수(*this)를 가지고 있다.

---

## 생성자, 소멸자
생성자와 소멸자는 객체가 생성되고 소멸될 때 호출되는 함수를 말한다.
* 생성자 : 멤버 변수의 초기화에 사용(오버로딩 가능)
* 소멸자 : 메모리 해제
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
// 7:5:16
``` 

---

## Static
전역으로 사용하고 싶고 Class와 밀접한 관계가 있거나 private 멤버 변수에 접근이 필요한 함수일 경우
``` cpp
#include <iostream>

using namespace std;

class Color{
    public:
    Color() : r(0), g(0), b(0), id(idCnt++) {}
    Color(float r,float g,float b) : r(r), g(g), b(b), id(idCnt++) {}

    float GetR() {return r;}
    float GetG() {return g;}
    float GetB() {return b;}
    
    float GetId() {return id;}

    static Color MixColors(Color a, Color b){
    
    return Color((a.GetR() + b.GetR()) /2, (a.GetG() + b.GetG()) /2,(a.GetB() + b.GetB()) /2);
    
    static int idCnt;
}

private:
    float r;
    float g;
    float b;
    
    int id;
};

int Color::idCnt = 1;

int main(){

    Color blue(0,0,1);
    Color red(0,0,1);

    Color purple = Color::MixColors(blue, red);

    cout << "r = " << purple.GetR() << "\ng =" << purple.GetG() << "\nb = " << purple.GetB() << endl;
    
    cout << "blue.GetId() = " << blue.GetId() << endl;
    cout << "red.GetId() = " << red.GetId() << endl;
    cout << "purple.GetId() = " << purple.GetId() << endl;

    return 0;

}
``` 

## Const
```cpp
const int a = 10;
a = 20; // error!
```
포인터 const
```cpp
int value = 5, value2 = 11;
const int * ptr = &value;
// *ptr = 10; // error! can't change const value
value = 10; // ok!
std::cout << value << " " << *ptr << std::endl; // 10 10
value = 7;
ptr = &value2;
std::cout << value << " " << *ptr << std::endl; // 7 11
```
함수 const
```cpp
 int def() cont {
     num++; // error
     // 함수에 const사용시 멤버변수의 값 변경 불가
 }
 private:
    int num;
 ```

## 연산자 오버로딩
operator(+, -, *, /)

## 동적할당
```cpp
int* arr = new int(3);
int* array1 = new int[5] { 9, 7, 5, 3, 1 };
char* array2 = new char[14] { "Hello, world!" };
int* dynamicArray1 = new int[] {1, 2, 3};

delete arr;
delete[] array1;
delete[] array2;
delete[] dynamicArray;
```

## 깊은복사 vs 얕은복사
1. 깊은복사 : 메모리 주소에 할당된 데이터를 복사
2. 얕은복사 : 메모리 주소만 참조

## vector
vector 생성
```cpp
# include <vector>
vector<int> v;  // 비어있는 vector v를 생성합니다.

vector<int> v(5);   // 기본값(0)으로 초기화 된 5개의 원소를 가지는 vector v를 생성합니다.

vector<int> v(5, 2);    // 2로 초기화된 5개의 원소를 가지는 vector v를 생성합니다.

// v2는 v1 vector를 복사해서 생성됩니다.
vector<int> v1(5, 2);
vector<int> v2(v1);
```
vector<int> v1; , vector<int> v2;  가 있고, 내부에 인자들이 있다고 했을때.

연산자 : "==", "!=", "<", ">", "<=", ">=" 로 대소비교 가 가능합니다.

vector 사용
* idx번째 원소 참조 : v.at(idx); 
* 모든원소 제거하고 메모리는 남아있습니다. : v.clear(); 
* 마지막 원소 뒤에 원소 n을 삽입합니다. : v.push_back(n);
* n개의 원소를 저장할 위치를 예약합니다(미리 동적할당 해놉니다) : v.reserve(n);
* 원소의 갯수를 리턴한다 : v.size();
