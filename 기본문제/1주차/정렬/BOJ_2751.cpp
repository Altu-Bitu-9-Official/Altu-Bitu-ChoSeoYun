#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> merged;

void merge(vector<int> &arr, int left, int mid, int right) {
  int pl = left, pr = mid + 1, idx = left;

  while (pl <= mid && pr <= right) {
    if (arr[pl] < arr[pr]) {
      merged[idx++] = arr[pl++]; //왼쪽더미 포인터 이동 
    } else {
      merged[idx++] = arr[pr++]; //오른쪽더미 포인터 이동
    }
  }
  while (pl <= mid){
    merged[idx++] = arr[pl++];
  }
    while (pr <= right){
    merged[idx++] = arr[pr++];
  }

  for(int i = left; i <=right; i++ ){
    arr[i] = merged[i];
  }
}
void mergeSort(vector<int> &arr, int left, int right) {
  // 나누기
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

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
  // merged라는 배열에 공간을 할당하겠다, n개의 칸에 0이라는 숫자가 채워져있다.
  merged.assign(n, 0);
  
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // bubbleSort(arr);
  //mergeSort(arr, 0, n - 1);

  sort(arr.begin(), arr.end()); //O(nlogn)

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}