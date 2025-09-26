#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
어느 소수의 배수로 지워졌는지 저장
이미 값이 존재한다면 갱신하지 않음
결과적으로 해당 인덱스의 가장 작은 소인수가 저장

모두 완료하면 역으로 경로조사 시작-!
*/

const int MAX = 5000000;

vector<int> getPrimes() {
  vector<int> primes(MAX + 1, 0);

  for (int i = 2; i <= sqrt(MAX); i++) {
    if (primes[i] != 0) {
      // 이미 다른 수에 의해 지워짐, 갱신X
      continue;
    }
    for (int j = i * i; j <= MAX; j += i) {
      if (primes[j] == 0) {
        // 아직 지워지지 않았다면,
        primes[j] = i;
      }
    }
  }
  return primes;
}

// 출력하는 함수
vector<int>
getPrimeFactor(int k, vector<int> &primes) { // 코드 전체의 메모리 줄이기 위함.
  vector<int> factors;

  while (primes[k] != 0) {
    factors.push_back(primes[k]);
    k /= primes[k];
  }
  factors.push_back(k); // k를 왜 넣어
  return factors;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n, k;
  cin >> n;

  // 배열을 채운 다음에 해당 숫자에 대한 소인수분해 결과를 출력
  vector<int> primes = getPrimes();

  while (n--) {
    cin >> k;
    vector<int> factors = getPrimeFactor(k, primes);

    for (int factor : factors) {
      cout << factor << " ";
    }
    cout << "\n";
  }

  return 0;
}