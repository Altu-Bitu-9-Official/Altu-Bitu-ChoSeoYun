#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
long long도 안됨;;
숫자를 문자열로?
스택
*/

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  stack<char> a;
  stack<char> b;
  stack<int> result;

  for (int i = 0; i < s1.size(); i++) {
    // stack에 넣기
    a.push(s1[i]);
  }

  for (int i = 0; i < s2.size(); i++) {
    // stack에 넣기
    b.push(s2[i]);
  }

  int q = 0; // 자리 올림

  while (!a.empty() || !b.empty()) {
    int digit1 = 0;
    int digit2 = 0;

    if (!a.empty()) {
      digit1 = a.top() - '0';
      a.pop();
    }

    if (!b.empty()) {
      digit2 = b.top() - '0';
      b.pop();
    }

    // 올림 처리
    int p = digit1 + digit2 + q;
    result.push(p % 10);
    q = p / 10;
  }

  if (q > 0) {
    result.push(q);
  }

  // 결과 출력
  while (!result.empty()) {
    cout << result.top();
    result.pop();
  }

  return 0;
}