#include <iostream>
#include <vector>
using namespace std;

// 행성 1, 2, ... , n-1을 순서대로 확인하고 행성 n에 돌아오는 것이 최적
// 필요한 속도의 양의 정수 배로도 다음 지역으로 이동할 수 있음
// 지구를 벗어나면 속도를 떨어뜨릴 수는 있지만 올릴 수는 없음
// 지구에서 올려야하는 속도를 최소화
// 뒤에서부터?

int main() {
  // 입력
  int N;
  cin >> N;

  vector<long long> planet(N);

  for (int i = 0; i < N; i++) {
    cin >> planet[i];
  }

  // 연산
  // 뒤에서부터
  long long currentSpeed = planet[N - 1];

  for (int i = N - 2; i >= 0; i--) {
    if (currentSpeed % planet[i] == 0) {
      continue;
    }
    currentSpeed = ((currentSpeed / planet[i] + 1) * planet[i]);
  }

  // 출력
  cout << currentSpeed;

  return 0;
}