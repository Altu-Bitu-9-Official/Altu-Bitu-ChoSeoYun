#include <iostream>
#include <vector>

using namespace std;

/*
바퀴에 같은 글자는 두 번 이상 등장하지 않는다.
바퀴를 돌릴 때 마다, 화살표가 가리키는 글자가 변하는 횟수와 어떤 글자에서 회전을
멈추었는지 종이에 적는다.
*/

int main() {

  int n, k;
  int s = 0;
  char c;

  cin >> n >> k;

  vector<char> wheel(n, '?');
  vector<bool> isFull(n, false);

  int current = 0;

  // 바퀴가 시계방향으로 돌아가려면, 0 다음에 마지막 인덱스가 와야 함.
  
  for (int i = 0; i < k; i++) {
    cin >> s >> c;
    current = (current - s + n) % n;

    // 배열이 차있고, 안에 있는 값과 넣으려는 값이 다르면,
    if (wheel[current] != '?' && wheel[current] != c) {
      cout << "!";
      return 0;
    }

    wheel[current] = c;
  }

  for (int i = 0; i < n; i++) {
    cout << wheel[(current + i) % n];
  }
}