
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string strSrc)
{
  string strReturn = "";    // 초기화

  const int nSize = strSrc.size();  // 문자열의 길이

  cout << "nSize : " << nSize << endl;

  vector<char> vctChar; // vector char를 만들고 이름은 vctChar
  vector<int> vctCount; // vector int를 만들고 이름은 vctCount

  vctChar.push_back(strSrc.at(0));  // 문자열의 첫번째를 vctChar에 삽입
  vctCount.push_back(1);    // vctCount뒤에 1 삽입

  bool bCheck = false;
  // 같은 글자가 몇개씩 있는지 확인하는 작업
  for(int i=1; i<nSize; ++i)    // 문자열을 모두 탐색
  {
    cout << "for in nSize : " << nSize << endl;

    bCheck = false;
    for(int j = 0; j<vctCount.size(); ++j)
    {
      if(vctChar[j] == strSrc.at(i))
      {
        ++vctCount[j];  // 같은 글자 나오면 vctCout에 +1
        bCheck = true;
        break;
      }
    }
    if(!bCheck)
    {      
      vctChar.push_back(strSrc.at(i));  // 새로운 글자 추가
      vctCount.push_back(1);    // 새로추가된 문자의 갯수
    }
  }

  vector<int> vctTemp = vctCount;   // 단어의 횟수를 체크했던 vec 복사
  sort(vctTemp.begin(), vctTemp.end()); // 같은거 몇개 나왔는지 확인하는 arr sort
  int nMaxCnt = vctTemp[vctTemp.size() - 1];    // 가장 숫자 많이 나온개 몇개인지 확인
  int nSecondCnt = 0;
  for(int i=0; i<vctTemp.size()-1; ++i)
  {
    if(nSecondCnt < vctTemp[i]) // 두번째로 크다고 정해놓은 숫자보다 크면 진입
    {
      if(vctTemp[i] == nMaxCnt) // 최대 숫자와 지금 확인하는 숫자가 같다면 break
        break;

      nSecondCnt = vctTemp[i];  // 2번째로 큰 숫자 정의
    }
  }
  if(nSecondCnt == 0)   // 위에 for문을 나왔는데 두번째로 큰 숫자가 0이라면 '_'반환
  { 
    return "-";
  }
  
  vector<char> vctSecondNum;    // 두번째로 많이 들어있는 글자들 모임
  for(int i=0; i<vctCount.size(); ++i)
  {
    if(vctCount[i] == nSecondCnt)
    {
      vctSecondNum.push_back(vctChar[i]);
    }
  }
  sort(vctSecondNum.begin(),vctSecondNum.end());
  for(int i=0;i<vctSecondNum.size(); ++i)
    strReturn += vctSecondNum[i];

  return strReturn;
}

int main(){
    string re = solution("jjeeddssvsr");

    cout << re << endl;

}