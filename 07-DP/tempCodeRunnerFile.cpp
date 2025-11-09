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

  // 연산
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;

    for(int j = 0; j < i; j++){
      if(a[j] < a[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }

  // 출력
  int maxLen = 0;
  for (int i = 0; i < dp.size(); i++) {
    if (dp[i] > maxLen) {
      maxLen = dp[i];
    }
  }
  
  cout << maxLen;

  return 0;
}