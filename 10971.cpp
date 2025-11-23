#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 도시 사이에 길이 있을 수도 없을 수도
// 한 외판원이 어느 한 도시에서 출발해 n개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로 계획
// 한 번 갔던 도시는 다시 방문할 수 없음.
// 가장 적은 비용을 들이는 여행 계획.

vector<vector<int> > v;
vector<bool> visited;
int n;
int start = 0;
int ans = INT_MAX;

void dfs(int current, int depth, int cost){
  if(depth == n){
    if(v[current][start] != 0){
      ans = min(ans, cost + v[current][start]);
    }

    return;
  }

  for (int i = 0; i < n; i++) {
    if (v[current][i] == 0) {
      continue;
    }

    if (visited[i]) {
      continue;
    }

    if(cost + v[current][i] >= ans){
      continue;
    }

    visited[i] = true;
    dfs(i, depth + 1, cost + v[current][i]);
    visited[i] = false;
  }
}
int main(){
  // 입력
  cin >> n;

  v.assign(n, vector<int>(n, 0));
  visited.assign(n, false);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> v[i][j];
    }
  }

  // 연산
  visited[start] = true;
  dfs(start, 1, 0);

  // 출력
  cout << ans;
  return 0;
}