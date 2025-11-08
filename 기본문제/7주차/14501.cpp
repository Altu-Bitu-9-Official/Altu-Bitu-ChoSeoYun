#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

void dpBottomUp(vector<int> &dp, vector<ii> &li, int n) {
  // 모든 일자에 대해 반복
  for (int i = 0; i < n; i++) {

    dp[i + 1] = max(dp[i + 1], dp[i]);

    // 해당 일자에 상담한다고 할 때, 가장 빠른 다음 상담일자부터 반복
    int next = i + li[i].first;
    if (next <= n) {
      dp[next] = max(dp[next], dp[i] + li[i].second);
    }
  }
}

int main() {
  // 입력
  int n;
  cin >> n;

  vector<ii> li(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> li[i].first >> li[i].second;
  }

  // 연산 & 출력
  vector<int> dp(n + 1);
  dpBottomUp(dp, li, n);

  cout << dp[n] << "\n";
  return 0;
}