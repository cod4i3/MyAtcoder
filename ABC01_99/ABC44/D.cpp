#include <cmath>
#include <iostream>
using namespace std;

long long func(long long b, long long n) {
  if (n < b)
    return n;
  else
    return func(b, n / b) + n % b;
}

int main() {
  long long n, s;
  cin >> n >> s;

  long long left = 1;
  long long right = 100000000000000;
  long long b;

  if (n < s) {
    cout << -1 << endl;
    return 0;
  }

  while (right - left > 1) {
    b = left + (right - left) / 2;

    if (func(b, n) == s) {
      cout << b << endl;
      return 0;
    }

    if (func(b, n) > s) {
      right = b;
    } else {
      left = b;
    }
  }

  cout << -1 << endl;
  return 0;
}