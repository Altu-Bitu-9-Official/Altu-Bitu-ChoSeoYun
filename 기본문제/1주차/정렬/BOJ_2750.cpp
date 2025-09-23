#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr) {
  // 벡터처럼 크기 큰 인자들은 바로 불러오기보다는 주소로 가져오는 것이 좋음.
  int len = arr.size();

  // i와 오른쪽에 정렬된 것의 개수와 같음.
  for (int i = 0; i < len - 1; i++) {
    // len - 1에서 i만큼 빼준 것만 비교하면 됨.
    for (int j = 0; j < len - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  bubbleSort(arr);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}