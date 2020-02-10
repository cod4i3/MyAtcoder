#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = A[i] - (i + 1);
  }
  sort(B.begin(), B.end());

  ll median = B[(B.size() + 1) / 2 - 1];
  ll ans = 0;
  for (int i = 0; i < N; i++) ans += abs(B[i] - median);
  cout << ans << endl;
  return 0;
}