#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
bool flag;
int N, K;
// int T[10][10];

void dfs(int Q, int sum, const vector<vector<int> > &T) {
  if (Q == N) {
    if (sum == 0) flag = true;
    return;
  }
  FOR(i, K) { dfs(Q + 1, sum ^ T[Q][i], T); }
}

int main() {
  cin >> N >> K;
  vector<vector<int> > T(N, vector<int>(K));
  FOR(i, N) FOR(j, K) cin >> T[i][j];
  dfs(0, 0, T);
  if (flag)
    cout << "Found" << endl;
  else
    cout << "Nothing" << endl;
  return 0;
}