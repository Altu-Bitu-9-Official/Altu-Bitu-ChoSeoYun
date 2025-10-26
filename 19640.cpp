#include <iostream>
#include <vector>
#include <queue>

// 임시 화장실의 앞에 데카를 포함한 N명의 사원이 대기
// 데카는 N명의 줄에서 K+1번째로 줄을 섰음. == 데카 앞에 K명이 있음.
// M개의 줄로 나눠서 대기하라
// 기존 줄의 1번째 사원은 1번째 줄에, 2번째 사원은 2번째 줄에
// M번째 사원은 M번째 줄에, 그리고 M+1번째 사원은 1번째 줄 뒤에 서는 방식

// 선두란 어떤 줄에서 가장먼저 와서 가장 앞에 선 사람을 말함.
// M개의 줄의 선두 중 근무일수 D가 가장 높은 선두가 화장실을 이용
// 공동인 경우 해당 선두들 중 화장실이 급한 정도 H가 가장 높은 선두가 화장실을
// 이용 이것도 공동인 경우 해당 선두 중 줄의 번호가 가장 낮은 줄에 선 선두가
// 화장실을 이용

// 몇 명의 사원이 화장실을 이용하고 나서야 데카의 차례가 올까?

using namespace std;

struct employee {
  int D, H, line_num, idx;
};

struct cmp {
  bool operator()(const employee &a, const employee &b) {
    if (a.D != b.D)
      return a.D < b.D;
    if (a.H != b.H)
      return a.H < b.H;
    return a.line_num > b.line_num;
  }
};

// 큐를 m개 선언? - 아닐듯

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<employee> > lines(m);

  for (int i = 0; i < n; i++) {
    int D, H;
    cin >> D >> H;
    lines[i % m].push_back({D, H, i % m, i});
  }

  priority_queue<employee, vector<employee>, cmp> pq;

  // 한 사람 빠지면 새 사람 넣기
  for (int i = 0; i < m; i++) {
    if (!lines[i].empty()) {
      pq.push(lines[i][0]);
    }
  }

  int count = 0;
  vector<int> front(m, 0);

  while (!pq.empty()) {
    // 차례가 되면 화장실 이용
    employee current = pq.top();
    pq.pop();

    // 데카 차례
    if (current.idx == k) {
      cout << count << '\n';
      return 0;
    }

    count++;

    int lineNum = current.line_num;
    front[lineNum]++;

    if (front[lineNum] < (int)lines[lineNum].size()) {
      pq.push(lines[lineNum][front[lineNum]]);
    }
  }

  return 0;
}