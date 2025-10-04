#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
최대한 함수로 빼기

R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로
*/

// 미리 정의
pair<int, int> dir(string move) {
  if (move == "R")
    return make_pair(1, 0);
  if (move == "L")
    return make_pair(-1, 0);
  if (move == "B")
    return make_pair(0, -1);
  if (move == "T")
    return make_pair(0, 1);
  if (move == "RT")
    return make_pair(1, 1);
  if (move == "LT")
    return make_pair(-1, 1);
  if (move == "RB")
    return make_pair(1, -1);
  if (move == "LB")
    return make_pair(-1, -1);

  return make_pair(0, 0);
}

// 숫자로 만들기
pair<int, int> toPair(string pos) {
  return make_pair(pos[0] - 'A', pos[1] - '1');
}

// 다시 문자로 만들기
string toString(pair<int, int> pos) {
  string s;
  s += char(pos.first + 'A');
  s += char(pos.second + '1');
  return s;
}

// 위치 찾기
void findPos(pair<int, int> &king, pair<int, int> &stone, string str) {
  pair<int, int> result = dir(str);

  int dx = result.first;
  int dy = result.second;

  // 왕 위치
  int current_kx = king.first + dx;
  int current_ky = king.second + dy;

  // 보드 범위 밖
  if (current_kx < 0 || current_kx >= 8 || current_ky < 0 || current_ky >= 8) {
    return;
  }

  // 돌과 충돌하면
  if (current_kx == stone.first && current_ky == stone.second) {
    int current_sx = stone.first + dx;
    int current_sy = stone.second + dy;

    // 돌이 보드 범위 밖으로 나가면
    if (current_sx < 0 || current_sx >= 8 || current_sy < 0 ||
        current_sy >= 8) {
      return;
    }

    // 돌 위치 업데이트
    stone = make_pair(current_sx, current_sy);
  }
  // 왕 위치 업데이트
  king = make_pair(current_kx, current_ky);
}

int main() {
  // 입력
  string k, s;
  int n;
  cin >> k >> s >> n;
  vector<string> str(n);

  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }

  pair<int, int> king = toPair(k);
  pair<int, int> stone = toPair(s);

  // 연산
  for (int i = 0; i < n; i++) {
    findPos(king, stone, str[i]);
  }    

  // 출력
  cout << toString(king) << "\n" << toString(stone) << "\n";

  return 0;
}
