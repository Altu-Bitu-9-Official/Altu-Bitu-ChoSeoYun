#include <iostream>
#include <vector>

using namespace std;

// 가지고 있는 동전 n 종류
// 동전을 적절히 사용해 가치의 합이 k가 되도록
// 필요한 동전 개수의 최솟값
// A1 = 1, An은 An-1의 배수 (n>=2)

int main () {
  int N, K, count = 0;
  cin >> N >> K;
  vector<int> A(N, 0);

  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  while (N--)
  {
    count += K / A[N]; // 동전 개수 저장
    K %= A[N]; // 나머지 저장 
  }
  
  cout << count;

  return 0;
}
