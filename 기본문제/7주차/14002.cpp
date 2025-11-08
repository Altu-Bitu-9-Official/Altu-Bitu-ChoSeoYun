#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // 입력
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> dp(n);

  int len = 0; // 가장 긴 부분 수열의 길이
  int tmp = 0; //
  int max_idx = -1; //가장 긴 부분 수열의 마지막 인덱스

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    len = 0;

    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        len = max(len, dp[j]);
      }
    }
    dp[i] = len + 1; // i번째에 있는 요소 포함

    if (tmp < dp[i]) {
      max_idx = i;
      tmp = dp[i];
    }
  }

  vector<int> ans;

  for (int i = max_idx; i >= 0; i--) {
    if(tmp == dp[i]){
      ans.push_back(a[i]);
      tmp--;
    }
    if(tmp == 0) break;
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << "\n";
  for(int x = 0; x < ans.size(); x++){
    cout << ans[x] << ' ';
  }
  return 0;
}