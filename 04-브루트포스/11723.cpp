#include <iostream>
#include <vector>

using namespace std;

/*
add x: S에 x를 추가한다. S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 가 있으면 1을, 없으면 0을 출력한다.
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다.
all: S를 {1,2,...,20}으로 바꾼다.
empty: S를 공집합으로 바꾼다.
*/

void calculate(vector<int>& S, string s, int x) {
  // 존재하는지 확인
  int isExist = false;
  int idx = -1;

  for (int i = 0; i < S.size(); i++) {
    if (S[i] == x) {
      isExist = true;
      idx = i;
      break;
    }
  }

  // 연산
  if (s == "add") {
    if (!isExist) {
      S.push_back(x);      
    }
  }

  if (s == "remove") {
    if (isExist) {
      S.erase(S.begin() + idx);
    }
  }

  if (s == "check") {
    if (isExist) {
      cout << "1" << "\n";
    } else{
      cout << "0" << "\n";
    }
  }

  if (s == "toggle") {
    if (isExist) {
      S.erase(S.begin() + idx);
    } else{
      S.push_back(x);
    }
  }

  if (s == "all") {
    S.clear();
    for (int j = 1; j <= 20; j++) {
      S.push_back(j);
    }
  }

  if (s == "empty") {
    S.clear();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 입력
  int M;
  cin >> M;

  vector<int> S;

  string cal;
  int x;

  // 연산 & 출력
  for (int i = 0; i < M; i++) {
    cin >> cal;
    if (cal == "add" || cal == "remove" || cal == "check" || cal == "toggle")
    {
      cin >> x;
    } else {
      x = 0;
    }
    
    calculate(S, cal, x);
  }

  return 0;
}
