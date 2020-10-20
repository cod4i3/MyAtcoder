#include <iostream>
#include <vector>
using namespace std;

int main() {
  int D;
  cin >> D;

  //満足度の下がりやすさ、満足度の増加量
  vector<int> c(26);
  vector<vector<int>> s(D, vector<int>(26));
  // コンテストの開催日程(1 <= t <= 26), B問題のみに存在
  vector<int> t(D);

  // 各コンテストが最後に実施された日数、初期値は0
  vector<int> last(26, 0);
  // 各日での満足度、初期値は0
  vector<int> v(D, 0);

  // 入力
  for (int i = 0; i < 26; i++) cin >> c[i];
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < 26; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < D; i++) cin >> t[i];

  for (int day = 0; day < D; day++) {
    last[t[day] - 1] = (day + 1);
    v[day] += s[day][t[day] - 1];
    cout << "v = " << v[day] << endl;
    for (int num = 0; num < 26; num++) {
      v[day] -= c[num] * ((day + 1) - last[num]);
    }
  }

  for (int day = 1; day < 26; day++) {
    v[day] += v[day - 1];
  }

  for (int day = 0; day < D; day++) cout << v[day] << endl;
  return 0;
}