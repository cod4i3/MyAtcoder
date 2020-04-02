#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR2(i, s, n) for (int i = (s); i < (int)(n); i++)
char maze[110][110];
int dp[110][110];

int main() {
  int H, W;
  cin >> H >> W;
  FOR(i, H) FOR(j, W) cin >> maze[i][j];

  FOR(i, H) FOR(j, W) dp[i][j] = 10000;

  if (maze[0][0] == '#')
    dp[0][0] = 1;
  else
    dp[0][0] = 0;

  FOR(i, H) FOR(j, W) {
    if (i - 1 >= 0) {
      if (maze[i][j] == '#' && maze[i - 1][j] == '.')
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      else
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    }
    if (j - 1 >= 0) {
      if (maze[i][j] == '#' && maze[i][j - 1] == '.')
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      else
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }

  /*
  FOR(i, H) {
    FOR(j, W) { cout << dp[i][j] << ' '; }
    cout << endl;
  }
  */

  cout << dp[H - 1][W - 1] << endl;
  return 0;
}