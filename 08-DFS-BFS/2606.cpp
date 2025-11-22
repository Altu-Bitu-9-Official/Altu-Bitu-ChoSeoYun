#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v;
vector<int> visited;

int virus(int node, int n) {
    int count = 1;
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (v[node][i] == 1 && !visited[i]) {
            count += virus(i, n);
        }
    }

    return count;
}

int main() {
    // 입력
    int n, c;
    cin >> n >> c;

    v.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, 0);

    int to, from;
    for (int i = 0; i < c; i++) {
        cin >> to >> from;
        v[to][from] = 1;
        v[from][to] = 1;
    }

    // 연산
    int result = virus(1, n) - 1; // 1번 제외

    cout << result;
    return 0;
}
