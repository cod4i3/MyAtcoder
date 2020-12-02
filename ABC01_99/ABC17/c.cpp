#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> l(N), r(N), s(N);
  vector<ll> S(M + 1);

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> l[i] >> r[i] >> s[i];
    l[i]--, r[i];
    S[l[i]] += s[i];
    S[r[i]] -= s[i];
    ans += s[i];
  }

  ll res = ans;
  for (int i = 1; i < M; i++) S[i] += S[i - 1];
  for (int i = 0; i < M; i++) res = min(res, S[i]);

  cout << ans - res << endl;
  return 0;
}