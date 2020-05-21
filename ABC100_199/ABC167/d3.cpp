// 自分で出したやつの改善例
#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 210000;
using namespace std;
using ll = long long;

int main() {
  ll N, K;

  cin >> N >> K;

  vector<ll> A(N + 1, 0);
  vector<int> seen(N + 1, -1), ans;

  FOR(i, N) cin >> A[i], A[i]--;

  ll cur = 0;
  ll cnt = 0;
  while (1) {
    if (seen[cur] >= 0) break;
    seen[cur] = cnt;
    if (ans.size() == K) return cout << cur + 1 << endl, 0;
    ans.emplace_back(cur);
    cnt++;
    cur = A[cur];
  }

  int start = seen[cur];
  int num = (K - start) % (cnt - start);

  cout << ans[start + num] + 1 << endl;

  return 0;
}
