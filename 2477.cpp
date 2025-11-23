#include <iostream>

using namespace std;

// 1m^2에 자라는 참외 개수 && 넓이 == 총 참외 개수
// 1m^2에 자라는 참외 개수 == k
// 참외 밭의 넓이 = ?

enum Direction {
    EAST = 1,  // 동
    WEST = 2,  // 서
    SOUTH = 3, // 남
    NORTH = 4  // 북
};

int main(){
  // 입력
  int k;
  cin >> k;

  int way[6];
  int len[6];

  int maxWidth = 0;
  int maxHeight = 0;
  int widthIndex = -1;
  int heightIndex = -1;

  for (int i = 0; i < 6; i++) {
    cin >> way[i] >> len[i];
  }

  // 연산
  for (int i = 0; i < 6; i++) {
    if (way[i] == EAST || way[i] == WEST) {
      if(len[i] > maxWidth){
        maxWidth = len[i];
        widthIndex = i;
      }
    } else if (way[i] == NORTH || way[i] == SOUTH) {
      if(len[i] > maxHeight){
        maxHeight = len[i];
        heightIndex = i;
      }
    }
  }

  int bigSquare = maxWidth * maxHeight;

  int smallW = abs(len[(heightIndex + 5) % 6] - len[(heightIndex + 1) % 6]);
  int smallH = abs(len[(widthIndex + 5) % 6] - len[(widthIndex + 1) % 6]);

  int smallSquare = smallW * smallH;


  int result = (bigSquare - smallSquare) * k;

  // 출력
  cout << result;
  return 0;
}