#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, W;
  cin >> N >> W;

  ll w, v;
  cin >> w >> v;
  vector<vector<ll>> V(4, vector<ll>());
  V[0].emplace_back(v);
  for (int i = 0; i < N - 1; i++) {
    ll W;
    cin >> W >> v;
    V[W - w].emplace_back(v);
  }

  for (int i = 0; i < 4; i++)
    if (V[i].size()) sort(V[i].begin(), V[i].end(), greater<ll>());

  vector<vector<ll>> cum(4, vector<ll>());
  for (int i = 0; i < 4; i++) {
    cum[i].emplace_back(0);
    cum[i].resize(V[i].size() + 1);
    for (int j = 0; j < int(V[i].size()); j++) {
      cum[i][j + 1] = cum[i][j] + V[i][j];
    }
  }

  ll ans = 0;
  for (int i = 0; i <= V[0].size(); i++) {
    for (int j = 0; j <= V[1].size(); j++) {
      for (int k = 0; k <= V[2].size(); k++) {
        for (int l = 0; l <= V[3].size(); l++) {
          if(w * i + (w + 1) * j + (w + 2) * k + (w + 3) * l <= W) ans = max(ans, cum[0][i] + cum[1][j] + cum[2][k] + cum[3][l]);
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}