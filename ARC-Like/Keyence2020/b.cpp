#include <algorithm>
#include <iostream>
using namespace std;
#define MAX_N 110000
typedef long long ll;
ll N, X[MAX_N], L[MAX_N];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> X[i] >> L[i];
  pair<ll, ll> itv[MAX_N];
  for (int i = 0; i < N; i++) {
    itv[i].first = X[i] + L[i];
    itv[i].second = X[i] - L[i];
  }

  sort(itv, itv + N);

  ll ans = 0, t = -10000000000;
  for (int i = 0; i < N; i++) {
    if (t <= itv[i].second) {
      ans++;
      t = itv[i].first;
    }
  }

  cout << ans << endl;
}