#include <iostream>

using namespace std;

/*
3개의 수가 지구, 태양, 달을 나타냄
지구 E
태양 S
달 M

그냥 다 돌아...
*/

int main() {
  int E, S, M;
  cin >> E >> S >> M;

  int e = 1, s = 1, m = 1;
  int count = 1;

  while (!(E == e && S == s && M == m)) {
    e += 1;
    s += 1;
    m += 1;

    if (e == 16) {
      e = 1;
    }

    if (s == 29) {
      s = 1;
    }

    if (m == 20) {
      m = 1;
    }

    count++;
  }

  cout << count;
  return 0;
}