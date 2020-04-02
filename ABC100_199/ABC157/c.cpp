#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  if (M == 0) {
    if (N == 1)
      cout << 0 << endl;
    else
      cout << pow(10, N - 1) << endl;
    return 0;
  }
  vector<pair<int, int> > P(M);
  REP(i, M) {
    int s, c;
    cin >> s >> c;
    P[i] = make_pair(s, c);
  }

  sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());

  int len = P.size();
  if (N == 1) {
    if (len > 1)
      cout << -1 << endl;
    else
      cout << P[0].second << endl;
    return 0;
  }

  string ans[N];
  REP(i, N) ans[i] = "-1";
  REP(i, len) {
    if (P[i].first == 1 && P[i].second == 0) {
      cout << -1 << endl;
      return 0;
    }
    if (ans[P[i].first - 1] != "-1") {
      cout << -1 << endl;
      return 0;
    }
    ans[P[i].first - 1] = to_string(P[i].second);
  }

  if (ans[0] == "-1") ans[0] = "1";
  if (ans[0] == "") ans[0] = "1";

  for (int i = 1; i < N; i++) {
    if (ans[i] == "-1") ans[i] = "0";
  }

  // REP(i, N) cout << "ans[" << i << "] = " << ans[i] << endl;
  REP(i, N) { cout << ans[i]; }
  cout << endl;
  return 0;
}