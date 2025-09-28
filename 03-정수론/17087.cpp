#include <iostream>
#include <vector>

using namespace std;
/*
|수빈이의 위치 - 동생들 위치|들끼리의 최대공약수
*/

int gcdIter(int a, int b) {
  while (b != 0) {
    a = a % b;
    swap(a, b);
  }

  return a;
}

int main() {

  int n;
  int x, gcd = 0;

  cin >> n >> x;
  vector<int> a(n);

  // 동생들의 위치 저장
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // 수빈이의 위치 - 동생의 위치를 저장할 벡터
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    d[i] = abs(x - a[i]);
  }

  // 위의 값들끼리의 최대공약수 구하기
  for (int i = 0 ; i< n; i++){
    gcd = gcdIter(gcd, d[i]);
  }

  cout << gcd << "\n";

  return 0;
}