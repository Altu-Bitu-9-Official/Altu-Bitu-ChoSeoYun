#include <iostream>
#include <vector>

using namespace std;

/*
주어진 n에 대해 에라토스테네스의 체를 적용했을 때, k번째 지우는 수 구하기

1. 2부터 N까지 모든 정수를 적는다.
2. 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는
소수이다.
3. P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
4. 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
*/

// 에라토스테네스의 체
int findPrime(int n, int k) {
  int cnt = 0;

  vector<int> is_Prime(n + 1, true);

  for (int i = 2; i <= n; i++) {
    if (!is_Prime[i]) { // 이미지 지워진 수이면 탐색하지 않음.
      continue;
    }

    for (int j = i; j <= n; j += i) {
      if (!is_Prime[j]) { // 이미 지워진 수이면 탐색하지 않음.
        continue;
      }
      is_Prime[j] = false;
      cnt++;

      if (cnt == k) {
        return j;
      }
    }
  }
}

int main() {

  int n, k;
  cin >> n >> k;

  cout << findPrime(n, k) << "\n";
  
  return 0;
}