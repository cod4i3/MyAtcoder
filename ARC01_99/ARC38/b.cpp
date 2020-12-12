#include <iostream>
#include <vector>
using namespace std;

vector<string> S;

// dp[i][j] = 座標(i, j)からスタートした場合勝つかどうか
vector<vector<int>> dp;
int H, W;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

int rec(int y, int x) {
  if (dp[y][x] != -1) return dp[y][x];
  int ret = 0;
  for (int i = 0; i < 3; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= H || nx >= W) continue;
    if (S[ny][nx] == '#') continue;
    if (rec(ny, nx) == 0) ret = 1;
  }

  dp[y][x] = ret;
  return ret;
}

int main() {
  cin >> H >> W;

  S.resize(H);
  dp.resize(H, vector<int>(W, -1));
  for (int i = 0; i < H; i++) cin >> S[i];
  cout << (rec(0, 0) ? "First" : "Second") << endl;
  return 0;
}