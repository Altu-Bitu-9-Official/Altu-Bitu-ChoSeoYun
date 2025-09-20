#include <iostream>
#include <map>

using namespace std;

int calcCar(const vector<int> &car_after) {
  int len = car_after.size();
  int ans = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (car_after[i] > car_after[j]) {
        ans++;
        break;
      }
    }
  }
  return ans;
}
int main() {
  int n;
  string input;
  map<string, int> car_num;
  vector<int> car_after;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> input;
    car_num[input] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> input;
    car_after.push_back(car_num[input]);
  }

  cout << calcCar(car_after);

  return 0;
}