#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> P(N);
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    p--;
    P[i] = make_pair(p, i);
  }

  sort(P.begin(), P.end());
  vector<int> ans;
  // どこの座標が何回交換したかを数える
  vector<int> cnt(N + 10);
  int res = 0;
  for (int i = 0; i < N; i++) {
    int num = P[i].first;
    // 今動かすべき数字の座標
    int plot = P[i].second;
    plot += cnt[plot];
    if (plot == num) continue;
    // 動いた回数
    for (int j = plot; j > num; j--) {
      ans.emplace_back(j);
      cnt[j - 1]++;
      res++;
    }
    cnt[plot]++;
    if (int(ans.size()) > N - 1) {
      cout << -1 << endl;
      return 0;
    }
  }

  // 残った動かす数が奇数回
  if (((N - 1) - res) % 2 || res > N - 1) {
    cout << -1 << endl;
    return 0;
  }

  bool flag = false;
  for (int i = 0; i < N; i++) {
    if (P[i].first != P[i].second) {
      flag = true;
    }
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < int(ans.size()); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}