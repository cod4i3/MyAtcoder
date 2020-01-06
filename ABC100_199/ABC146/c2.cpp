#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define MAX 1000000000;

ll digit(ll N) {
  ll digit = 0;
  while (N != 0) {
    N /= 10;
    digit++;
  }
  return digit;
}

int main() {
  ll A, B, X;
  cin >> A >> B >> X;
  ll left = 0;
  ll right = 1000000001;

  ll mid = 0;
  while (right - left > 1) {
    int mid = left + (right - left) / 2;

    if (X >= A * mid + B * digit(mid))
      left = mid;
    else
      right = mid;
  }

  /*
  for (ll N = pow(10, digit - 1); N < pow(10, digit); N++) {
    if (A * N + B * d(N) <= X) ans = N;
    if (N == 1000000000) break;
  }
  */

  cout << left << endl;
  return 0;
}