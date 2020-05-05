#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  vector<ll> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];

  vector<vector<int>> G(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<int> good(N, 0);
  for (int i = 0; i < N; i++) {
    bool flag = true;
    if (G[i].size() == 0) {
      good[i] = 1;
      continue;
    }

    for (int j = 0; j < G[i].size(); j++) {
      if (H[G[i][j]] >= H[i]) flag = false;
    }
    if (flag) good[i] = 1;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (good[i] == 1) ans++;
  }

  cout << ans << endl;
  return 0;
}