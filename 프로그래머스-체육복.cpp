#include <iostream>
#include <vector>
using namespace std;

// 여벌 옷이 있는 학생은 바로 앞 혹은 뒷번호 학생에게 체육복을 빌려줄 수 있음.
// 전체 학생 수 N, 도난 당한 학생의 번호가 담긴 배열 lost
// 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reverse

int solution(int n, vector<int> lost, vector<int> reverse) {
  int answer = 0;

  // 처음에는 모두가 체육복을 가지고 있다가 도난 당하는 것이기에 1로 초기화
  vector<int> clothes(n+1, 1);
  
  // 잃어버린 학생들의 인덱스
  for(int i = 0; i < lost.size(); i++){
    clothes[lost[i]]--;
  }
  // 여벌 옷 가지고 있는 학생의 인덱스
  for(int i = 0; i < reverse.size(); i++){
    clothes[reverse[i]]++;
  }

  for (int i = 0; i < n; i++)
  {
    if(clothes[i] == 1){
      continue;
    } else {
      // 앞 번호의 학생 먼저 탐색
      if (clothes[i - 1] == 2) {
        clothes[i]++;
        clothes[i - 1]--;
      }
      // 뒷 번호의 학생 탐색
      else if (clothes[i + 1] == 2) {
        clothes[i]++;
        clothes[i + 1]--;
      }
    } 
  }

  for(int i = 0; i <= n; i++){
    if(clothes[i]){
      answer++;
    }
  }
  
  return answer; 
}