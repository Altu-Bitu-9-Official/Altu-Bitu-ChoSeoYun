#include <iostream>
#include <vector>

using namespace std;

int main(){
  // 입력
  int n;
  cin >> n;

  vector<int> dp(n+1,0); // 2xn 크기의 직사각형을 채우는 방법의 수 

  // 연산 (1이랑 2로 n을 채워라랑 다를게 없긴 해)
  dp[1] = 1;
  dp[2] = 2;

  for(int i = 3; i <= n; i++){
    dp[i] = (dp[i-1] + dp[i-2]) % 10007;
  }
  // 출력
  cout << dp[n];
  
  return 0;
}
