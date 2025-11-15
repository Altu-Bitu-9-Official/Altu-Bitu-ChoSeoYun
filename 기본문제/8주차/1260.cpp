#include <cstring> // memset
#include <iostream>
#include <queue>

// stack은 재귀함수로 대체
using namespace std;
// 방문할 수 있는 점이 여러 개인 경우, 정점 번호가 작은 것부터 방문

int n, m, v;
int graph[1001][1001] = {
    0,
};
bool visited[1001] = {
    false,
};
int dfs_ans[1001] = {
    0,
};
int bfs_ans[1001] = {
    0,
};
int idx = 1;

void dfs(int from){
  for(int i = 1; i <= n; ++i){
    if(graph[from][i] == 1){
      if(!visited[i]){
        visited[i] = true;
        dfs_ans[idx++] = i;
        dfs(i);
      }
    }
  }
}

void bfs(int start){
  queue<int> q;
  q.push(start);

  while(!q.empty()){
    int now = q.front();
    q.pop();

    for(int i = 1; i <= n; ++i){
      if(graph[now][i] == 1){
        if(!visited[i]){
          visited[i] = true;
          bfs_ans[idx++] = i;
          q.push(i);
        }
      }
    }
  }
}

int main() { 
  // 입력
  cin >> n >> m >> v;

  for(int i = 0; i < m; ++i){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
  }

  // 연산
  dfs_ans[0] = bfs_ans[0] = v;
  visited[v] = true;
  dfs(v);

  memset(visited, false, sizeof(visited));
  visited[v] = true;
  idx = 1;
  bfs(v);
  
  // 출력
  for(int i = 0; i < n; ++i){
    if(dfs_ans[i] == 0){
      break;
    } else {
      cout << dfs_ans[i] << ' ';
    }
  }
  cout << '\n';
  for(int i = 0; i < n; ++i){
    if(dfs_ans[i] == 0){
      break;
    } else {
      cout << bfs_ans[i] << ' ';
    }
  }

  return 0; 
}