#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
아홉 난쟁이 중에 일곱 명을 뽑는 것

아홉 난쟁이의 키를 다 더한 후 두 난쟁이의 키를 빼고 100인지 확인
*/

const int CNT = 9;

void select(vector<int> &height) {
  int sum = 0;

  // 난쟁이 9명의 키 합
  for (int i = 0; i < CNT; i++) {
    sum = sum + height[i];
  }

  for (int i = 0; i < CNT; i++) {       // 1번째 난쟁이
    for (int k = i + 1; k < CNT; k++) { // 2번째 난쟁이
      if (sum - (height[i] + height[k]) == 100) {
        height.erase(height.begin() + k);
        height.erase(height.begin() + i); //큰 난쟁이부터 
        return;
      }
    }
  }
}

int main() {
  // 입력
  vector<int> height(CNT);

  for (int i = 0; i < CNT; i++) {
    cin >> height[i];
  }

  // 연산
  select(height);
  sort(height.begin(), height.end());

  // 출력
  for(auto it : height){
    cout << it << "\n";
  }
}