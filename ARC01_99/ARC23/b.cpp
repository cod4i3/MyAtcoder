#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_R = 1010;
const int MAX_C = 1010;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int R, C, D;
vector<vector<int>> A(MAX_R, vector<int>(MAX_C));

int ans = 0;
bool seen[MAX_R][MAX_C];
int dis[MAX_R][MAX_C];

void dfs(vector<vector<int>> &A, int y, int x, int d) {
  seen[y][x] = true;
  dis[y][x] = d;

  if (D % 2 == dis[y][x] % 2) ans = max(ans, A[y][x]);

  for (int i = 0; i < 2; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny + nx > D) return;
    if (seen[ny][nx]) continue;
    if (0 <= ny && ny < R && 0 <= nx && nx <= C) {
      dfs(A, ny, nx, d + 1);
    }
  }
  return;
}

int main() {
  cin >> R >> C >> D;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> A[i][j];
    }
  }

  dfs(A, 0, 0, 0);

  cout << ans << endl;
  return 0;
}