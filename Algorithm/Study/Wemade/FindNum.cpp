#include <iostream>
#include <string.h>

using namespace std;

int solution(int nNum)
{
  int nStringSize = 0;  // 받은 숫자의 길이

  bool bCheck = false;
  while(!bCheck)
  {
    do
    {
      //숫자 자릿수 짝수나올때까지 ++
      nStringSize = std::to_string(nNum++).size();  // to_string 숫자 타입의 데이터를 안전하게 스트링 타입으로 변경
    } while(nStringSize%2);

    --nNum;

    cout << "중간 체크" << nNum << endl;

    int nFront = 1;
    int nEnd = 1;

    std::string strNum = std::to_string(nNum);  // 숫자를 문자열로 변경
    int nCntNum = 0;
    for(int i = 0; i < nStringSize / 2; ++i)    // 전체 숫자의 길이중 절반
    {
      nCntNum = strNum.at(i) - '0'; // 아스키코드
      nFront *= nCntNum;
    }
    for(int i = nStringSize / 2; i < nStringSize; ++i)
    {
      nCntNum = strNum.at(i) - '0';
      nEnd *= nCntNum;
    }
    
    nFront != nEnd ? ++nNum : bCheck=true;
  }

  return nNum;
}