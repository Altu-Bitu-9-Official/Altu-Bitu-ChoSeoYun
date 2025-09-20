#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

/*
기타를 시리얼 번호 순서대로 정렬
기타A와 기타B의 길이가 다르면, 짧은 것이 우선
길이가 같으면, 각 기타의 모든 자리 수의 합을 비교해서 작은 합 우선(only 숫자) 
모든 자리 수의 합이 같으면 사전 순으로 비교 (숫자가 알파벳보다 우선) 
시리얼을 정렬해서 출력
*/

struct guitar {
  string serialNum;
  int len, sum;
};

bool comp(const guitar &g1, const guitar &g2) {
  if (g1.len != g2.len) {
    return g1.len < g2.len;
  }
  if (g1.sum != g2.sum) {
    return g1.sum < g2.sum;
  }
  return g1.serialNum < g2.serialNum;
}

int main() {
  int N;
  cin >> N;

  vector<guitar> g(N);

  // 시리얼 넘버 입력받기, 길이&합 계산
  for (int i = 0; i < N; i++) {
    cin >> g[i].serialNum;
    g[i].len = g[i].serialNum.size();

    for (int j = 0; j < g[i].len; j++) {
      if (isdigit(g[i].serialNum[j])) {
        g[i].sum += g[i].serialNum[j] - '0';
      }
    }
  }

  sort(g.begin(), g.end(), comp);

  for (int i = 0; i < N; i++) {
    cout << g[i].serialNum << '\n';
  }

  return 0;
}
