#include <iostream>
#include <queue>

using namespace std;

// 첫 번째 원소가 부모, 두 번째 원소가 자식
// swap 해야할 때 true를 반환
struct cmp {
  bool operator()(const int &child, const int &parent){
    if(abs(child) != abs(parent)){
      return abs(parent) < abs(child);
    }
    return parent < child;
  }
};

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x;
  cin >> n;

  // 기본이 최대 힙
  priority_queue<int, vector<int>, cmp> pq;

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