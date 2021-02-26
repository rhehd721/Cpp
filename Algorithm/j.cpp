
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string strSrc)
{
  string strReturn = "";    // 초기화

  const int nSize = strSrc.size();  // 문자열의 길이

  vector<char> vctChar;
  vector<int> vctCount;

  vctChar.push_back(strSrc.at(0));
  vctCount.push_back(1);

  bool bCheck = false;
  for(int i=1; i<nSize; ++i)
  {
    bCheck = false;
    for(int j = 0; j<vctCount.size(); ++j)
    {
      if(vctChar[j] == strSrc.at(i))
      {
        ++vctCount[j];
        bCheck = true;
        break;
      }
    }
    if(!bCheck)
    {      
      vctChar.push_back(strSrc.at(i));
      vctCount.push_back(1);
    }
  }

  vector<int> vctTemp = vctCount;
  sort(vctTemp.begin(), vctTemp.end());
  int nMaxCnt = vctTemp[vctTemp.size() - 1];
  int nSecondCnt = 0;
  for(int i=0; i<vctTemp.size()-1; ++i)
  {
    if(nSecondCnt < vctTemp[i])
    {
      if(vctTemp[i] == nMaxCnt)
        break;

      nSecondCnt = vctTemp[i];
    }
  }
  if(nSecondCnt == 0)
  { 
    return "-";
  }
  
  vector<char> vctSecondNum;
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