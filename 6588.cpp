#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.

곱셈은 더하기랑 같으니까
소인수분해를 하고 그 수들이 모두 홀수이면
홀수인 소수 두 개의 합으로 만들 수 있겠지-!

홀수 * 홀수 = 홀수
홀수 * 짝수 = 짝수
짝수 * 짝수 = 짝수
*/

const int MAX = 10000000;
vector<int> is_Prime(MAX + 1, true);

void findPrime(){
  for (int i = 2; i <= MAX; i++) {
    if (!is_Prime[i]) { // 이미지 지워진 수이면 탐색하지 않음.
      continue;
    }

    for (int j = i * 2; j <= MAX; j += i) {
      if (!is_Prime[j]) { // 이미 지워진 수이면 탐색하지 않음.
        continue;
      }
      is_Prime[j] = false;
    }
  }
}

bool isPrime(int num){
  return is_Prime[num];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, a, b;
  b = n - a;

  findPrime();

  // 0이 들어올 때까지
  while (true) {
    cin >> n;

    for (int i = 1; i < sqrt(n); i++) {
      a = a - i;

      isPrime(a);
      if (!isPrime(a)) {
        break;
      }

      isPrime(b);
      if (!isPrime(b)) {
        break;
      }

      break;
    }

    // a가 젤 작고 b가 젤 큰 것이 b-a값이 항상 젤큼.
    cout << n << " =" << a << " +" << b << "\n";
  }

  return 0;
}
