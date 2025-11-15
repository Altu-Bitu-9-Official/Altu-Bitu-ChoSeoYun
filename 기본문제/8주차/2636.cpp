#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 치즈가 녹아 없어지는데 걸리는 시간,
// 모두 녹기 한 시간 전 치즈 조각이 놓여있는 칸의 개수
// 치즈가 녹는 과정에서 여러 조각으로 나누어 질 수도 있음.

int row, col;
int graph[100][100] = {0, };
bool visited[100][100] = {false, };
int ti, result = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool bfs(){
  // 공기의 좌표를 탐색
  // 치즈를 만나면 탐색을 멈춤
  int cnt = 0; // 이번 턴에서 녹인 치즈의 개수
  // 0,0을 시작점으로 (치즈가 무조건 없음.)

  queue<pair<int, int> > q;
  visited[0][0] = true;
  q.push({0,0});

  while(!q.empty()){
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for(int i = 0; i < 4; ++i){
      int nr = r + dy[i];
      int nc = c + dx[i];

      if(nr >= 0 && nr < row && nc >= 0 && nc < col){
        if(!visited[nr][nc]){
          // 치즈가 아닐 경우
          if(graph[nr][nc] == 0){
            visited[nr][nc] = true;
            q.push({nr, nc});
          }
          // 치즈일 경우
          else {
            visited[nr][nc] = true;
            graph[nr][nc] = 0; // 치즈가 녹아서 공기가 됨
            cnt++;
          }
        }
      }
    }
  }
  if(cnt == 0){
    return true;
  }
  else {
    result = cnt;
    return false;
  }
}

int main(){
  // 입력
  cin >> row >> col;
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < col; ++j){
      cin >> graph[i][j];
    }
  }
  
  // 연산
  while(true){
    if(bfs()){ 
      break; // 치즈가 다 녹음.
    } else {
      memset(visited, false, sizeof(visited));
      ti++;
    } 
  }

  // 출력
  cout << ti << '\n' << result;
  return 0;
}