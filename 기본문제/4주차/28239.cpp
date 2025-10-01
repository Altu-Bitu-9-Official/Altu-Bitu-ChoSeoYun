#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;
const int MAX = 60;

pair<int, int> getXY(ll m){
  int x, y;

  //m = 2^i
  //m = 2^(i-1) + 2^(i-1), x = y = i -1

  for(int i = 0; i < MAX; i++){
    if(m == (ll)1 << i){
      return make_pair(i-1, i-1);
    }
  }

  for(x = 0; x < MAX; x++){
    if(m & ((ll)1 << x)){
      m -= (ll)1 << x;
      break;
    }
  }

  for(y = x + 1; y < MAX; y++){
    if(m & ((ll)1 << y)){
      break;
    }
  }

  return make_pair(x, y);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //입력
  int n;
  cin >> n;

  //연산 & 출력
  while(n--){
    ll m;
    cin >> m;
    pair<int, int> ans = getXY(m);
    cout << ans.first << " " << ans.second << "\n";
  }

  return 0;
}