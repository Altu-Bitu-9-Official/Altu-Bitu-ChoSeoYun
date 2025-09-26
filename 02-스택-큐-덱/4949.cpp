#include <iostream>
#include <stack>

using namespace std;

/*
어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단

모든 왼쪽 소괄호는 오른쪽 소괄호와만 짝을 이룸
모든 왼쪽 대괄호는 오른쪽 대괄호와만 짝을 이룸
모든 오른쪽 괄호들은 자신과 짝을 이루는 왼쪽 괄호 존재
모든 괄호들은 1:1 매칭
짝을 이루는 두 괄호가 있을 때, 그 사이의 문자열도 균형이 잡혀야 함.
*/

int main() {

  string str;

  while (true) {

    stack<char> s;

getline(cin, str);
cout << "읽은 줄: [" << str << "]" << endl; // 버퍼 확인
if (str == ".") break;

    bool isBalanced = true;

    for(int i = 0; i < str.size(); i ++){
      if (str[i] == '(' || str[i] == '['){
        s.push(str[i]);
      } else if (str[i] == ')') {
        if(s.empty() || s.top() != '('){
          isBalanced = false;
          break;
        }
        s.pop();
      } else if (str[i] == ']'){
        if(s.empty() || s.top() != '['){
          isBalanced = false;
          break;
        }
        s.pop();
      }
    }

    if(!s.empty()){
      isBalanced = false;
    }

    if(isBalanced){
      cout << "yes" << "\n";
    } else {
      cout << "no" << "\n";
    }
  }

  return 0;
}