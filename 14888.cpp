#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int operation[4];
int maxValue = INT_MIN;
int minValue = INT_MAX;

// dfs 공부 더 하기 ㅠㅠ
void dfs(int depth, int value) {
  if (depth == n) {
    maxValue = max(maxValue, value);
    minValue = min(minValue, value);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (operation[i] > 0) {
      operation[i]--;

      int next = value;
      if (i == 0) {
        next = value + v[depth];
      } else if (i == 1) {
        next = value - v[depth];
      } else if (i == 2) {
        next = value * v[depth];
      } else if (i == 3) {
        if (value < 0) {
          next = -(-value / v[depth]);
        } else {
          next = value / v[depth];
        }
      }
      dfs(depth + 1, next);

      operation[i]++;
    }
  }
}

int main() {
  // 입력
  cin >> n;

  v.assign(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  // 덧셈 - 뺄셈 - 곱셈 - 나눗셈
  for (int i = 0; i < 4; i++) {
    cin >> operation[i];
  }

  // 연산
  dfs(1, v[0]);

  // 출력
  cout << maxValue << "\n" << minValue << "\n";
}