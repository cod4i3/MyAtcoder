#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int L;
  cin >> L;
  vector<ll> A(L);

  ll res = 0, a = 0, b;
  // b[i] = a[i] ^ a[i + 1]
  // a[i + 1] = a[i] ^ b[i];
  // a[0] = 0とすればあとは流れで
  for (int i = 0; i < L; i++) {
    cin >> b;
    A[(i + 1) % L] = b ^ A[i];
  }

  if (A[0] != 0) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < L; i++) {
      cout << A[i] << endl;
    }
  }
  return 0;
}