#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > relation;
vector<int> visited;
vector<int> dist;

int bfs(int start, int target, int n){
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  dist[start] = 0;

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int i = 1; i <= n; i++){
      if(relation[current][i] == 1 && !visited[i]){
        visited[i] = 1;
        dist[i] = dist[current] + 1;
        q.push(i);

        if(i == target){
          return dist[i];
        }
      }
    }
  }

  return -1;
}

int main(){
  // 입력
  int n;
  cin >> n;
  
  int p1, p2;
  cin >> p1 >> p2;

  int m;
  cin >> m;

  relation.assign(n + 1, vector<int>(n + 1, -1));
  visited.assign(n + 1, 0);
  dist.assign(n + 1, -1);

  int x, y;
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    relation[x][y] = 1;
    relation[y][x] = 1;
  }

  // 연산
  int ans = bfs(p1, p2, n);

  // 출력
  cout << ans;
  return 0;
}