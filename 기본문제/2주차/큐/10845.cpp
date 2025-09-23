#include <iostream>
#include <queue>

using namespace std;

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는
경우에는 -1을 출력한다. back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에
들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<int> q;
  int front = 0, rear = 0; // 초기화 할 때는 front와 rear가 동일하게

  string cmd;
  int n, x;
  cin >> n;

  while (n--) {
    cin >> cmd;

    if (cmd == "push") {
      cin >> x;
      q.push(x);
    }

    else if (cmd == "pop") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.front() << "\n";
        q.pop();
      }
    }

    else if (cmd == "size") {
      cout << q.size() << "\n";
    }

    else if (cmd == "empty") {
      cout << q.empty() << "\n";
    }

    else if (cmd == "front") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.front() << "\n";
      }
    }

    else if (cmd == "back") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.back() << "\n";
      }
    }
  }
  return 0;
}
