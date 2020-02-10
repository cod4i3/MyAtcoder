#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  for (int i = 1; i < N; i++) {
    if (A[i] == A[i - 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}