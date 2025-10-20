#include <iostream>
#include <queue>

using namespace std;

// 삽입이랑 삭제를 구현하라

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x;
  cin >> n;

  // 기본이 최대 힙
  priority_queue<int> pq;
  priority_queue<int, vector<int>, greater<int> > min_heap;

  while (n--) {
    cin >> x;
    switch (x) {
    case 0:
      // 삭제
      if (!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
      } else {
        cout << "0\n";
      }
      break;

    default:
      // 삽입
      pq.push(x);
      break;
    }
  }

  return 0;
}