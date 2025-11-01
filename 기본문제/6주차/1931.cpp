#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 한 개의 회의실, N개의 회의 존재
// 각 회의 I의 시작시간, 끝나는 시간 주어짐
// 회의끼리 겹칠 수 없음
// 회의는 한번 시작하면 중단될 수 없음
// 회의의 시작시간 == 끝나는시간이면 시작하자마자 끝나는 것

int main() {
  int N, count = 0;

  vector<pair<int, int> > arr;

  cin >> N;
  arr.assign(N, {0,0});

  // 시간 입력:  끝나는 시간 기준으로 문제를 풂
  // 편의상 끝나는 시간을 first로 설정
  for (int i = 0; i < N; i++) {
    cin >> arr[i].second >> arr[i].first;
  }

  // 끝나는 시간을 오름차순으로 정렬
  sort(arr.begin(), arr.end());

  // 이전 회의가 끝나는 시간
  int finish_time = 0;
  for(int i = 0; i < N; i++){
    // 회의의 시작시간이 이전 회의의 종료시간보다 클 때
    if(finish_time <= arr[i].second){
      finish_time = arr[i].first;
      count++;
    }
  }

  cout << count;

  return 0;
}