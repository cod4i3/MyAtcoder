#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll max(ll a, ll b) { return ((a > b) ? a : b); }

int main() {
  int N;
  cin >> N;
  vector<ll> X, Y;
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    X.emplace_back(x - y);
    Y.emplace_back(x + y);
  }
  ll Xmin = 2e10, Ymin = 2e10, Xmax = -2e10, Ymax = -2e10;

  for (int i = 0; i < N; i++) {
    Xmin = min(Xmin, X[i]);
    Xmax = max(Xmax, X[i]);
    Ymin = min(Ymin, Y[i]);
    Ymax = max(Ymax, Y[i]);
  }

  cout << max(Xmax - Xmin, Ymax - Ymin) << endl;

  return 0;
}