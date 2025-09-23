#include <deque>
#include <iostream>

using namespace std;

/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다. 입력
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  string cmd;
  int x;
  deque<int> dq;

  while (n--) {
    cin >> cmd;

    if (cmd == "push_front") {
      cin >> x;
      dq.push_front(x);
    } else if (cmd == "push_back") {
      cin >> x;
      dq.push_back(x);
    } else if (cmd == "pop_front") {
      if (dq.empty()) {
        cout << "-1\n";
      } else {
        cout << dq.front() << "\n";
        dq.pop_front();
      }
    } else if (cmd == "pop_back") {
      if (dq.empty()) {
        cout << "-1\n";
      } else {
        cout << dq.back() << "\n";
        dq.pop_back();
      }
    } else if (cmd == "size") {
      cout << dq.size() << "\n";
    } else if (cmd == "empty") {
      cout << dq.empty() << "\n";
    } else if (cmd == "front") {
      if (dq.empty()) {
        cout << "-1\n";
      } else {
        cout << dq.front() << "\n";
      }
    } else if (cmd == "back") {
      if (dq.empty()) {
        cout << "-1\n";
      } else {
        cout << dq.back() << "\n";
      }
    }
  }
  return 0;
}