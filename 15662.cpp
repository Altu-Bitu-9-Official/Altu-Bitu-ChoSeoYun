#include <iostream>
#include <vector>

using namespace std;
// T는 톱니바퀴의 개수
// 회전시킬 톱니바퀴와 회전시킬 방향을 결정
// 맞닿은 극이 다르면 서로 반대 방향으로 회전
// 최종 톱니바퀴의 상태는?

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 입력
  int T, count = 0;
  cin >> T;

  vector<vector<int> > wheel(T, vector<int>(8, 0));

  // 12시 방향이 0번 인덱스
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> wheel[i][j];
    }
  }

  int K;
  cin >> K;
  // first - 회전시킨 톱니바퀴 번호, second - 방향

  vector<int> start(T, 0);
  vector<int> rotate(T, 0);

  // 연산
  // 맞닿는 부분은 2번 인덱스와 6번 인덱스

  for (int i = 0; i < K; i++) {
    int num, rot;
    cin >> num >> rot;
    num--;

    rotate[num] = rot;

    // 왼쪽
    for (int j = num - 1; j >= 0; j--) {
      int right = (start[j + 1] + 6) % 8; 
      int left = (start[j] + 2) % 8;
      if (wheel[j][left] == wheel[j + 1][right]) break;
      rotate[j] = -rotate[j + 1];
    }

    // 오른쪽
    for (int j = num + 1; j < T; j++) {
      int left = (start[j - 1] + 2) % 8;
      int right = (start[j] + 6) % 8;
      if (wheel[j - 1][left] == wheel[j][right]) break;
      rotate[j] = -rotate[j - 1];
    }

    // 회전
    for (int i = 0; i < T; i++) {
      if (rotate[i] == 1) // 시계 방향
        start[i] = (start[i] + 7) % 8;
      else if (rotate[i] == -1) // 반시계 방향
        start[i] = (start[i] + 1) % 8;
    }
  }

  // 출력 - 12시 방향이 S극인 톱니바퀴의 개수
  for (int i = 0; i < T; i++) {
    if (wheel[i][start[i]] == 1)
      count++;
  }
  cout << count;

  return 0;
}