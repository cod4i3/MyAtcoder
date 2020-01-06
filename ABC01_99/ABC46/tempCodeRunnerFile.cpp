#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(int a, int b) {
  int r;
  if (a < b) swap(a, b);
  while (a % b != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
  int N;
  cin >> N;

  // 比率はx:y
  int x[N], y[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  ll A = x[0], B = y[0];
  for (int i = 0; i < N; i++) {
    ll n1 = A / x[i];
    ll n2 = B / y[i];
    if (A % x[i] != 0) n1++;
    if (B % y[i] != 0) n2++;
    ll n = max(n1, n2);
    cout << n1 << " " << n2 << endl;
    A = n * x[i];
    B = n * y[i];
  }

  cout << A + B << endl;
  return 0;
}