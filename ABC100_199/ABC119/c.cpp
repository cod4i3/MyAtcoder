#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int N, A, B, C;
int ans = 0;

void dfs(vector<int> &l, int i, int mp, int l1, int l2, int l3) {
  if (i == N) {
    if (l1 == 0 || l2 == 0 || l3 == 0) return;
    ans = min(ans, abs(A - l1) + abs(B - l2) + abs(C - l3) + mp);
    return;
  }
  if (l1 != 0)
    dfs(l, i + 1, mp + 10, l1 + l[i], l2, l3);
  else
    dfs(l, i + 1, mp, l1 + l[i], l2, l3);

  if (l2 != 0)
    dfs(l, i + 1, mp + 10, l1, l2 + l[i], l3);
  else
    dfs(l, i + 1, mp, l1, l2 + l[i], l3);

  if (l3 != 0)
    dfs(l, i + 1, mp + 10, l1, l2, l3 + l[i]);
  else
    dfs(l, i + 1, mp, l1, l2, l3 + l[i]);

  dfs(l, i + 1, mp, l1, l2, l3);
  return;
}

int main() {
  cin >> N >> A >> B >> C;
  vector<int> l(N);
  for (int i = 0; i < N; i++) cin >> l[i];
  ans = 1000000;
  dfs(l, 0, 0, 0, 0, 0);
  cout << ans << endl;
  return 0;
}