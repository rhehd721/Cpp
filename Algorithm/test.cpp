
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> s;

  s.push_back(3);

  cout << s.size() << endl;




  s.erase(s.begin() + 0);

  cout << s.size() << endl;
}
