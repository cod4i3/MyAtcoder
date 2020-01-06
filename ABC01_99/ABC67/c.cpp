#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define MAX 1000000000000000

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  vector<ll> x(N, 0);
  vector<ll> y(N, 0);
  REP(i, N) {
    cin >> a.at(i);
    sum += a.at(i);
  }

  x.at(0) = a.at(0);
  y.at(0) = sum - x.at(0);
  REP2(i, 1, N - 1) {
    x.at(i) = x.at(i - 1) + a.at(i);
    y.at(i) = sum - x.at(i);
  }

  ll ans = MAX;
  REP(i, N - 1) ans = min(ans, abs(x.at(i) - y.at(i)));
  cout << ans << endl;
  return 0;
}