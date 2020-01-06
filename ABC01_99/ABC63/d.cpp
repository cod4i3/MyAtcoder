#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MAX_N 1000000
typedef long long ll;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll h[MAX_N];
  ll hmax = 0;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
    hmax = max(hmax, h[i]);
  }
  ll left = 0, right = hmax;

  while (abs(right - left) > 1) {
    ll T = left + (right - left) / 2;
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
      ll res;
      if (h[i] - B * T >= 0) {
        res = h[i] - B * T;
        cnt += res / (A - B);
        res -= (res / (A - B)) * (A - B);
        if (res) cnt++;
      }
    }

    if (cnt > T)
      left = T;
    else
      right = T;
  }

  cout << right << endl;
  return 0;
}