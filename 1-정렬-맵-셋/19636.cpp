#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

// 다이어트 전에는 하루 섭취량과 기초 대사량이 I0로 같음
// 다이어트 시작 후에는 달라짐(변수 새로 설정해야할듯)

// 다이어트 함수
pair<int, int> diet(int weight, int I, int basal, int active, int t, int d) {
  
  // I-일일 에너지 섭취량, basal-일일 기초대사량, active-일일 활동대사량

  for (int i = 0; i < d; i++) {
    int eUse = basal + active; //소비량

    weight = weight + I - eUse;

    if (abs(I - eUse) > t) {
      basal += floor((double)(I - eUse) / 2);
    }

    if (weight <= 0 || basal <= 0) {
      // 데시 사망
      return {weight, basal};
    }
  }

  return {weight, basal};
}

int main() {

  /*
  W0 - 다이어트 전 몸무게
  I0 - 다이어트 전 일일 에너지 섭취량 && 일일 기초대사량
  I - 다이어트 중 일일 에너지 섭취량
  A - 다이어트 중 일일 활동 대사량
  W - 다이어트 후 몸무게
  basal - 다이어트 중 기초대사량
  */

  int W0, I0, T;
  cin >> W0 >> I0 >> T;

  int D, I, A;
  cin >> D >> I >> A;

  int W = W0;
  int basal = I0;

  int W1 = W0;

  // 기초대사량 변화를 고려하지 않았을 때 예상 체중 및 일일 기초대사량
  for (int i = 0; i < D; i++) {
    // 체중 변화
    W1 += (I - (I0 + A));
  }

  if (W1 <= 0) {
    cout << "Danger Diet" << '\n';
  } else {
    cout << W1 << ' ' << I0 << '\n';
  }

  // 기초대사량 변화를 고려했을 때 예상 체중 및 일일 기초대사량
  pair<int, int> result = diet(W, I, basal, A, T, D);
  W = result.first;
  basal = result.second;

  if (W <= 0 || basal <= 0) {
    cout << "Danger Diet\n";
  } else {
    cout << W << ' ' << basal << ' ';
    if (basal < I0) {
      cout << "YOYO\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}