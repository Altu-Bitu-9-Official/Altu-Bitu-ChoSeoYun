#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
*/

const int MAX = 10000000;
vector<bool> is_Prime(MAX + 1, true);

void findPrime() {

  is_Prime[0] = false;
  is_Prime[1] = false;

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

bool isPrime(int num) { return is_Prime[num]; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  findPrime();

  // 0이 들어올 때까지
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    
    bool found = false;
    int a = 0, b = 0;

    for (int i = 3; i <= n / 2; i += 2) {
      a = i;
      b = n - a;

      if (isPrime(a) && isPrime(b)) {
        // a가 젤 작고 b가 젤 큰 것이 b-a값이 항상 젤큼.
        cout << n << " = " << a << " + " << b << "\n";
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "Goldbach's conjecture is wrong." << "\n";
    }
  }

  return 0;
}
