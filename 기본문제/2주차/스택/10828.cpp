#include <iostream>
#include <stack>

using namespace std;

/*
1. push X : 정수 X를 스택에 삽입
2. pop : 스택에서 가장 위에 있는 정수를 빼고, 출력. 스택이 비었다면 -1 출력
3. size : 스택에 들어있는 정수의 개수 출력
4. empty : 스택이 비었으면 1, 아니라면 0을 출력
5. top : 스택의 가장 위에 있는 정수를 출력. 스택이 비었다면 -1 출력
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<int> s;

  /* 
  스택
  vector<int> arr(MAX_SIZE);
  */
  int top = -1;


  int n, x;
  string cmd;
  cin >> n;

  while (n--) {
    cin >> cmd;

    if (cmd == "push") {
      cin >> x;
      s.push(x);
    } 
    
    else if (cmd == "pop") {
      if (s.empty()) {
        cout << "-1\n";
      } else {
        cout << s.top() << "\n";
        s.pop(); //없애기만 하고 반환은 안함.
      }
    } 
    
    else if (cmd == "size") {
      cout << s.size() << "\n";
    } 
    
    else if (cmd == "empty") {
      if (s.empty()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } 
    
    else if (cmd == "top") {
      if (s.empty()) {
        cout << "-1\n";
      } else {
        cout << s.top() << "\n";
      }
    }
  }

  return 0;
}