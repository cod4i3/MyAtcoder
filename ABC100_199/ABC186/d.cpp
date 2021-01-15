#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), S(N + 1, 0), B(N + 1, 0);

  for (int i = 0; i < N; i++) cin >> A[i];

  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++) {
    S[i + 1] = A[i] * i;
    B[i + 1] = A[i] * (N - 1 - i);
  }

  ll ans = 0;
  for (int i = 0; i <= N; i++) ans += S[i] - B[i];
  cout << ans << endl;
  return 0;
}