#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using T = tuple<ll, int, int>;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int H, W;
  cin >> H >> W;

  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};

  vector<vector<ll>> a(H, vector<ll>(W));
  vector<tuple<ll, ll, ll>> t;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      t.emplace_back(make_tuple(a[i][j], i, j));
    }
  }
  sort((t).rbegin(), (t).rend());

  vector<vector<ll>> dp(H, vector<ll>(W, 1));
  for (int i = 0; i < int(t.size()); i++) {
    ll y = get<1>(t[i]), x = get<2>(t[i]);
    for (int j = 0; j < 4; j++) {
      ll nx = x + dx[j], ny = y + dy[j];
      if (0 <= nx && nx < W && 0 <= ny && ny < H) {
        if (a[y][x] > a[ny][nx]) {
          dp[ny][nx] += dp[y][x];
          dp[ny][nx] %= MOD;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans += dp[i][j];
      ans %= MOD;
    }
  }


  cout << ans << endl;
  return 0;
}