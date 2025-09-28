#include <iostream>
#include <queue>

using namespace std;

/*
1. 제일 위에 있는 카드를 바닥에 버린다.
2. 제일 위에 있는 카드를 제일 아래 있는 카드 밑으로 옮긴다.
3. 마지막으로 남게 되는 카드를 구하세요.
*/

int main() {

  int n;
  cin >> n;

  queue<int> q;

  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  while (q.size() > 1) {
    q.pop();
    q.push(q.front());
    q.pop();
  }

  cout << q.front() << "\n";
  return 0;
}