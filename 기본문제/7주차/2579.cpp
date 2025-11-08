#include <iostream>
#include <vector>

using namespace std;

int getMaxScore(int n, vector<int> &score){

  vector<int> DP(n+1, 0); //DP[i]: i번째 계단까지 왔을 때 점수의 최댓값

  // 초기값
  DP[1] = score[1];
  DP[2] = score[1] + score[2];

  // 점화식 
  for(int i = 3; i <= n; i++){
    int one_step_before = DP[i-3] + score[i-1];
    int two_steps_before = DP[i-2];

    DP[i] = max(one_step_before, two_steps_before) + score[i];
  }

  return DP[n];
}
int main() {
  // DP[i] = MAX(DP[i-2], DP[i-3] + score[i-1]) + score[i]

  // 입력
  int N;
  cin >> N;
  vector<int> score(N + 1, 0);
  
  // score[i] -> i번째 계단의 점수
  for(int i = 1; i <= N; i++){
    cin >> score[i];
  }

  int ans = getMaxScore(N, score);
  cout << ans << "\n";
  
  return 0;
}