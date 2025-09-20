#include <cctype>
#include <iostream>
#include <map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int m, n;
  map<string, int> name;
  map<int, string> num;
  string input;
  cin >> m >> n;

  for(int i=1; i<=m; i++){
    cin >> input;
    name[input] = i;
    num[i] = input;
  }

  for(int i = 0; i<n; i++){
    cin >> input;

    if(isdigit(input[0])){
      cout << num[stoi(input)];
    } else {
      cout << name[input] << '\n';
    }
  }
  return 0;
}