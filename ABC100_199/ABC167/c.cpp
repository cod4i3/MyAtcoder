#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 15
#define MAX_M 15
using ll = long long;

int main() {
  ll N, M, X;
  ll ans = (1L << 60);
  vector<int> C(MAX_N);
  vector<vector<int>> A(MAX_N, vector<int>(MAX_M));
  // 理解度
  vector<int> U(MAX_M);

  bool flag = false;
  cin >> N >> M >> X;

  FOR(i, N) {
    cin >> C[i];
    FOR(j, M) { cin >> A[i][j]; }
  }

  FOR(bits, 1 << N) {
    ll sum = 0;

    FOR(i, M) { U[i] = 0; }

    FOR(i, N) {
      if (bits & (1 << i)) {
        FOR(j, M) U[j] += A[i][j];
        sum += C[i];
      }
    }

    ll cnt = 0;
    FOR(i, M) {
      if (U[i] >= X) cnt++;
    }

    if (cnt == M) {
      flag = true;
      ans = min(ans, sum);
    }
  }

  if (flag)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}