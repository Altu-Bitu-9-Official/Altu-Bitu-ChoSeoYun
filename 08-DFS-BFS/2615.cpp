#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v(20, vector<int>(20, 0));

int dr[4] = {0, 1, 1, -1};
int dc[4] = {1, 0, 1, 1};


void scan(){
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      if(v[i][j] == 0){
        continue;
      }

      int color = v[i][j];

      for(int k = 0; k < 4; k++){
        int preRow = i - dr[k];
        int preCol = j - dc[k];

        if(preRow >= 0 && preRow < 19 && preCol >=0 && preCol <19 && v[preRow][preCol] == color){
          continue;
        }

        int cnt = 1;
        int curRow = i + dr[k];
        int curCol = j + dc[k];

        while(curRow >= 0 && curRow < 19 && curCol >=0 && curCol <19 && v[curRow][curCol] == color){
          cnt++;
          curRow += dr[k];
          curCol += dc[k];
        }

        if(cnt == 5){
          int nextRow = i + dr[k] * 5;
          int nextCol = j + dc[k] * 5;

          if (nextRow >= 0 && nextRow < 19 && nextCol >= 0 && nextCol < 19 &&
              v[nextRow][nextCol] == color) {
            continue;
          }
          
          cout << color << "\n" << i+1 << " " << j+1;
          return;
        }
      }
    }
  }
  cout << 0;
}

int main(){
  // 입력
  for(int i = 0; i < 19; i++){
    for(int j = 0; j < 19; j++){
      cin >> v[i][j];
    }
  }

  // 연산 & 출력
  scan();
  
  return 0;
}