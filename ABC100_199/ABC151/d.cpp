#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
int dist[20][20];

// ベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int H, W;
char maze[20][20];

int search(int sx, int sy, int gx, int gy) {
  queue<P> que;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) dist[i][j] = -1;

  que.push(P(sx, sy));
  dist[sx][sy] = 0;

  while (!que.empty()) {
    // キューの先頭を取り出す
    P p = que.front();
    que.pop();

    // ゴールなら終了
    if (p.first == gx && p.second == gy) return dist[gx][gy];

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx && nx < H && 0 <= ny && ny < W && maze[nx][ny] != '#' &&
          dist[nx][ny] == -1) {
        que.push(P(nx, ny));
        dist[nx][ny] = dist[p.first][p.second] + 1;
      }
    }
  }

  return 0;
}

int main() {
  cin >> H >> W;
  REP(i, H) {
    REP(j, W) { cin >> maze[i][j]; }
  }

  int ans = 0;
  REP(sx, H) {
    REP(sy, W) {
      REP(gx, H) {
        REP(gy, W) {
          if (maze[sx][sy] != '#' && maze[gx][gy] != '#')
            ans = max(ans, search(sx, sy, gx, gy));
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}






