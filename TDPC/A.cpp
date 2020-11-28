#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool dp[10100];

int main() {
  int N;
  cin >> N;

  vector<int> p(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    sum += p[i];
  }

  // 問題の番号, 配点の合計
  vector<vector<bool> > memo(N + 1, vector<bool>(sum + 1, false));

  memo[0][0] = true;

  for (int num = 1; num < N + 1; num++) {
    for (int val = 0; val <= sum; val++) {
      if (val - p[num - 1] < 0) {
        memo[num][val] = memo[num - 1][val];
      } else {
        memo[num][val] = memo[num - 1][val] || memo[num - 1][val - p[num - 1]];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < sum + 1; i++) {
    if (memo[N][i]) ans++;
  }

  cout << ans << endl;
  return 0;
}