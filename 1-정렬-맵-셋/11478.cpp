#include <iostream>
#include <set>
#include <string>

using namespace std;

/*
S의 서로 다른 부분 문자열의 개수 구하기
부분 문자열 == S에서 연속된 일부분 (길이 1보다 크거나 같음)
*/

//중복된 원소를 포함하지 않는 자료구조(set)
//substring으로 뽑은 부분문자열을 set에 넣고, set의 길이 출력

int main() {
  string str;
  cin >> str;

  set<string> subString;

  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < str.size(); j++) {
      string s = str.substr(i, j);
      subString.insert(s);
    }
  }

  cout << subString.size();
  return 0;
}
