#include <iostream>
#include <deque>

using namespace std;

// 그냥 할리갈리 규칙
// 근데 종 치는 조건: 어느 쪽의 그라운드도 비어있으면 안됨!!
// 아 숫자 합이 5가 되면 수연이가 치고
// 그냥 5가 나오면 도도가 치고

int main() {
  // 입력
  int n, m;
  cin >> n >> m;

  deque<int> do_deck(n), su_deck(n);
  deque<int> do_ground, su_ground;

  // 연산
  // 게임 진행 중 덱에 있는 카드 수가 0개가 되면 상대방이 승리 - 
  // 기존 덱에 있는 카드 수 + 그라운드에 있는 카드 수 추가

  for (int i = 0; i < n; i++) {
      cin >> do_deck[i] >> su_deck[i];
  }

  bool do_turn = true;

  // M번 진행
  while (m--) {
    // 카드 내기
    if(do_turn){
      do_ground.push_back(do_deck.back());
      do_deck.pop_back();
    } else {
      su_ground.push_back(su_deck.back());
      su_deck.pop_back();
    }

    if(do_deck.size() == 0){
      cout << "su";
      return 0;
    } else if (su_deck.size() == 0){
      cout << "do";
      return 0;
    }

    // 수연 종 치기
    if (!do_ground.empty() && !su_ground.empty() &&
        do_ground.back() + su_ground.back() == 5) {
        while(do_ground.size()>0){
          su_deck.push_front(do_ground.front());
          do_ground.pop_front();
        }
        while(su_ground.size()>0){
          su_deck.push_front(su_ground.front());
          su_ground.pop_front();
        }
    }
    // 도도 종 치기
    else if ((!do_ground.empty() && do_ground.back() == 5) ||
             (!su_ground.empty() && su_ground.back() == 5)) {

      while (su_ground.size() > 0) {
        do_deck.push_front(su_ground.front());
        su_ground.pop_front();
      }

      while (do_ground.size() > 0) {
        do_deck.push_front(do_ground.front());
        do_ground.pop_front();
      }
    }

    do_turn = !do_turn;
  }

  // 출력
  if (do_deck.size() > su_deck.size()) cout << "do";
  else if (do_deck.size() < su_deck.size()) cout << "su";
  else cout << "dosu";
  
  return 0;
}
