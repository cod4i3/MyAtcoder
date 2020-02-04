#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > S(M);
  REP(i, M) {
    int k;
    cin >> k;
    S[i].resize(k);
    REP(j, k) cin >> S[i][j];
  }
  vector<int> p(M);
  REP(i, M) cin >> p[i];

  int ans = 0, cnt = 0;
  REP(bit, 1 << N) {
    int sum = 0;
    REP(i, M) {
      cnt = 0;
      REP(j, S[i].size()) {
        if (1 << (S[i][j] - 1) & bit) cnt++;
      }
      if (cnt % 2 == p[i]) sum++;
    }
    if (sum == M) ans++;
  }

  cout << ans << endl;
}