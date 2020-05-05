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
int d[MAX_R][MAX_C];
void bfs(vector<vector<int>> &A) {
  queue<pair<int, int>> que;
  que.push(make_pair(0, 0));
  if (D % 2 == 0) ans = A[0][0];
  d[0][0] = 0;

  while (!que.empty()) {
    pair<int, int> p = que.front();
    que.pop();
    int y = p.first, x = p.second;
    if (seen[y][x]) continue;
    seen[y][x] = true;

    for (int i = 0; i < 2; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx + ny > D) break;
      if (0 <= nx && nx < C && 0 <= ny && ny < R) {
        que.push(make_pair(ny, nx));
        d[ny][nx] = d[y][x] + 1;
        if (D % 2 == d[ny][nx] % 2) ans = max(ans, A[ny][nx]);
      }
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

  bfs(A);

  cout << ans << endl;
  return 0;
}
