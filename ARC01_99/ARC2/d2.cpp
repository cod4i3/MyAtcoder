#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using Graph = vector<vector<int> >;

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N + 1);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    G[x - 1].push_back(y - 1);
  }
  if (M == 0) {
    cout << 1 << endl;
    return 0;
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    int cnt = 1;
    bool can = true;
    for (int i = 0; i < N; i++) {
      if (((1 << i) & bit) > 0) {
        cnt = 1;
        for (int y : G[i]) {
          if (((1 << y) & bit) == 0)
            can = false;
          else
            cnt += 1;
        }
        if (can) ans = max(ans, cnt);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
