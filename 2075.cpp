#include <iostream>
#include <queue>

// 우선순위 큐에 하나씩 집어넣어야 할 것 같음!
// 메모리초과...
// 최소 힙으로 변경해서 젤 큰 n개의 수만 저장

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x;
  cin >> n;

  priority_queue<int, vector<int>, greater<int> > minHeap;

  // 입력
  for (int i = 0; i < n * n; i++) {
    cin >> x;
    if (minHeap.size() < n) {
      minHeap.push(x);
    } else if (x > minHeap.top()) {
      minHeap.pop();
      minHeap.push(x);
    }
  }

  // 출력
  cout << minHeap.top() << '\n';

  return 0;
}