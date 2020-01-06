// 失敗、四つをxorで足すと0になることを利用せよ

#include <iostream>
using namespace std;
// sheepが1, wolfが2
bool one[4] = {1, 1, 0, 0};
bool two[4] = {1, 0, 1, 0};

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;

  // 4パターンのアニマルを作る。
  bool animal[4][110000];
  for (int i = 2; i < N - 2; i++) {
    // 一つ目と二つ目を決める。
    for (int j = 0; j < 4; j++) {
      animal[j][0] = one[j];
      animal[j][1] = two[j];

      // 残りは自動的に決まる
      if (animal[j][i] == 1) {
        if (s.at(i) == 'o')
          animal[j][i + 1] = animal[j][i - 1];
        else
          animal[j][i + 1] = animal[j][i - 1] ^ 1;
      } else {
        if (s.at(i) == 'o')
          animal[j][i + 1] = animal[j][i - 1] ^ 1;
        else
          animal[j][i + 1] = animal[j][i - 1];
      }
    }
  }

  int flag;
  for (int i = 0; i < 4; i++) {
    if (s.at(N - 1) == 'o') {
      if (animal[i][N - 1] && (animal[i][N - 2] & animal[i][0])) {
        flag = i;
        break;
      }
      if (!animal[i][N - 1] && (animal[i][N - 2] ^ animal[i][0])) {
        flag = i;
        break;
      }
    } else {
      if (!animal[i][N - 1] && (animal[i][N - 2] & animal[i][0])) {
        flag = true;
        break;
      }
      if (animal[i][N - 1] && (animal[i][N - 2] ^ animal[i][0])) {
        flag = true;
        break;
      }
    }
  }

  if (flag) {
    char ans[N];
    for (int i = 0; i < N; i++) {
      ans[i] = (animal[flag][i]) ? 'S' : 'W';
    }
    for (int i = 0; i < N; i++) cout << ans[i];
    cout << endl;
  } else
    cout << -1 << endl;
  return 0;
}