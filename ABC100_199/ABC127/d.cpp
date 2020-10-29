#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, ll>> P;
  priority_queue<ll, vector<ll>, greater<ll>> A;
  REP(i, N) {
    ll a;
    cin >> a;
    A.push(a);
  }
  REP(i, M) {
    int b;
    ll c;
    cin >> b >> c;
    P.emplace_back(make_pair(c, b));
  }

  sort(P.rbegin(), P.rend());
  int cur = 0;
  while (N) {
    if (P[cur].second == 0) cur += 1;
    if(cur == P.size()) break;
    if (A.top() < P[cur].first) {
      A.push(P[cur].first);
      P[cur].second -= 1;
      A.pop();
    }
    N--;
  }

  ll ans = 0;
  while (!A.empty()) {
    ans += A.top();
    A.pop();
  }

  cout << ans << endl;
  return 0;
}