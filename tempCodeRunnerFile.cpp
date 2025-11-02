#include <iostream>
using namespace std;
// 사람들은 자신의 위치에서 거리가 K 이하인 햄버거를 먹을 수 있음.
// 식탁길이 N, 햄버거 선택 가능 거리 K
// 햄버거를 먹을 수 있는 사람의 최대 수

int main(){
  int N, K, count = 0;
  cin >> N >> K;

  string str;
  cin >> str;

  vector<bool> isEaten(N,false);

  int idx = 0;
  while (idx < N) {
    if (str[idx] == 'P') {
      for (int i = -K; i <= K; i++) {
        int pos = idx + i;
        if (pos < 0 || pos >= N) {
          continue;
        }

        if (str[pos] == 'H' && !isEaten[pos]) {
          isEaten[pos] = true;
          count++;
          break;
        }
      }
    }
    idx++;
  }

  cout << count;
  
  return 0;
}