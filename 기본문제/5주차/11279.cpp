#include <iostream>
#include <vector>

using namespace std;

// 삽입이랑 삭제를 구현하라

bool isEmpty(vector<int> &heap) { return heap.size() == 1; }

// 삽입 함수
void push(int x, vector<int> &heap) {
  int idx = heap.size();
  // 삽입
  heap.push_back(x);

  // 정렬
  while (idx > 1 && heap[idx] > heap[idx / 2]) {
    swap(heap[idx], heap[idx / 2]);
    idx = idx / 2;
  }
}

int pop(vector<int> &heap) {
  int item = heap[1];
  heap[1] = heap[heap.size() - 1];
  heap.pop_back();

  int parent = 1, child = 2;
  int size = heap.size();

  // 1. 왼쪽 오른쪽 비교
  // 2. 둘 중 큰 자식이 나보다 클 때 바꿈
  while (child < size) {
    // 오른쪽도 있다는 전제
    if (child + 1 < size && heap[child] < heap[child + 1]) {
      child++;
    }
    if (heap[child] > heap[parent]) {
      swap(heap[child], heap[parent]);
      parent = child;
      child = parent * 2;
    } else {
      break;
    }
  }
  return item;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x;
  cin >> n;

  // 첫 번째 인덱스는 사용 안함.
  vector<int> heap(1, 0);

  while (n--) {
    cin >> x;
    switch (x) {
    case 0:
      // 삭제
      if (!isEmpty(heap)) {
        cout << pop(heap) << "\n";
      } else {
        cout << "0\n";
      }
      break;

    default:
      // 삽입
      push(x, heap);
      break;
    }
  }

  return 0;
}