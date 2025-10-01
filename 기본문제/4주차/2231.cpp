#include <iostream>

using namespace std;

/*
분해합 = 숫자를 이루는 각 자리수의 합
생성자 = 분해합이 n인 어떤 자연수 m

245의 분해합 = 245 + 2 + 4 + 5 = 256
245는 256의 생성자
*/

int bruteforce(int n) {
  for(int i = 1; i < n; i++){
    int sum = i; //분해합 결과를 담는 변수
    int temp = i; //자릿수

    while(temp){
      sum += temp % 10; //마지막 자릿수를 구하기
      temp /= 10;
    }

    if(n == sum){
      return i;
    }
  }
  //생성자를 찾지 못한 경우
  return 0;
}

int main(){
  //입력
  int n;
  cin >> n;

  //연산
  int ans = bruteforce(n);

  //출력
  cout << ans;

  return 0;
}