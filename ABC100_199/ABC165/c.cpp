#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_Q 55

int N, M, Q;
vector<int> a(MAX_Q), b(MAX_Q), c(MAX_Q), d(MAX_Q);
int ans;

void dfs(int cur, int num, vector<int> &A) {
  if (cur >= N) {
    int sum = 0;
    FOR(i, Q) {
      if (A[b[i]] - A[a[i]] == c[i]) sum += d[i];
    }
    ans = max(ans, sum);
    return;
  }
  A[cur] = num;
  for (int i = 0; num + i <= M; i++) {
    dfs(cur + 1, num + i, A);
  }

  return;
}

int main() {
  cin >> N >> M >> Q;
  FOR(i, Q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
  }

  vector<int> A(N + 1, 0);

  for (int i = 1; i <= N; i++) dfs(0, i, A);

  cout << ans << endl;
  return 0;
}