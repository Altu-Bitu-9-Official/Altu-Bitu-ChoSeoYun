#include <cmath>
#include <iostream>
#include <vector>

// 같은 구성의 조건
// 1. 두 개의 단어가 같은 종류의 문자로 이루어져 있다.
// 2. 같은 문자는 같은 개수 만큼 있다.

// 비슷한 단어의 조건
// 두 단어가 같은 구성이거나,
// 한 단어에서 한 문자를 더하거나, 뺴거나,
// 하나의 문자를 다른 문자로 바꾸어 나머지 한 단어와 같은 구성을 갖게 되는 경우

// 첫 번째 단어와 비슷한 단어가 모두 몇 개인지 출력하세요

// 두 단어가 같은 구성이려면
// - 알파벳 개수는 같고 순서는 다르거나 같거나
// - 알파벳 개수가 다른데 한 개만 달라야됨(단어의 길이는 같거나, 1 차이나거나)

using namespace std;

// 각 알파벳 개수 세기
vector<int> countAlphabet(const string word) {
  vector<int> result(26, 0);
  for (int i = 0; i < word.size(); i++) {
    result[word[i] - 'A']++;
  }
  return result;
}

// 비슷한 단어인가요
bool isSimilar(string &first, string &str, vector<int> &firstA, vector<int> &strA) {
  int diff = 0;
  for (int i = 0; i < 26; i++) {
    diff += (abs)(firstA[i] - strA[i]);
  }
  int d = first.size() - str.size();

  // 단어의 길이가 같을 때
  if (d == 0) {
    if (diff == 0 || diff == 2) {
      return true;
    } else {
      return false;
    }
  } else {
  // 단어 길이가 다를 때 (1 차이여야만)
    if (d == 1 || d == -1) {
      if (diff == 1) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
}

int main() {
  // 입력
  int n, count = 0;
  cin >> n;

  string first_word;
  cin >> first_word;

  string s;
  vector<int> first_countAlphabet = countAlphabet(first_word);

  for (int i = 0; i < n - 1; i++) {
    cin >> s;
    vector<int> str_countAlphabet = countAlphabet(s);

    // 비슷한 단어인지 확인
    if (isSimilar(first_word, s, first_countAlphabet, str_countAlphabet)) {
      count++;
    }
  }

  // 출력
  cout << count << '\n';
  return 0;
}