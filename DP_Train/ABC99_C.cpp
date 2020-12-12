// 再帰DP
#include <iostream>
#include <vector>
using namespace std;
// memo[i] = i円引き出すのに何回かかるか
vector<int> memo;
int rec(int n) {
  if (n == 0) return memo[0] = 0;
  if (memo[n] != -1) return memo[n];
  // 今の金額
  int res = n;
  for (int i = 1; i <= n; i *= 6) res = min(res, rec(n - i) + 1);
  for (int i = 1; i <= n; i *= 9) res = min(res, rec(n - i) + 1);
  return memo[n] = res;
}

int main() {
  int N;
  cin >> N;
  memo.resize(N + 10, -1);
  cout << rec(N) << endl;
  return 0;
}