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

  ll value, ans = 0;
  for (ll N = 0; A * N <= X; N++) {
    value = A * N + B * digit(N);
    if (value <= X) ans = N;
    if (N == 1000000000) break;
  }

  cout << ans << endl;
  return 0;

  cout << digit(12345) << endl;
}