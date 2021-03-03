
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> s;

  s.push_back(3);
  s.push_back(5);
  s.push_back(4);

  for (int i : s){
    cout << i << endl;
    if(i == 5){
      s.erase(s.begin() + 1);
    }
  }

  cout << s.size() << endl;

  s.erase(s.begin());
  s.erase(s.begin());

  cout << s.size() << endl;
  
}
