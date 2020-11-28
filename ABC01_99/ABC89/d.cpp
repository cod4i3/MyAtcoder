#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int H, W, D;
  cin >> H >> W >> D;

  vector<pair<int, int>> A(H * W + 10);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      A[a - 1] = make_pair(i, j);
    }
  }

  vector<bool> seen(H * W + 10, false);
  vector<ll> S(H * W, 0);
  for (int i = 0; i < H * W; i++) {
    if (seen[i]) continue;
    for (int j = i; j < H * W; j += D) {
      seen[j] = true;
      if (j >= D) {
        S[j] = S[j - D];
        S[j] += abs(A[j].first - A[j - D].first) +
                abs(A[j].second - A[j - D].second);
      }
    }
  }

  int Q;
  cin >> Q;
  vector<ll> ans(0);
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    ans.emplace_back(S[r] - S[l]);
  }

  for (int i = 0; i < Q; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}