#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

typedef pair<int, int> P;
int dist[55][55];

// ベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int N, M;
  int sx, sy;
  int gx, gy;
  char maze[51][51];
  //最短距離
  int dist[51][51];

  cin >> N >> M;
  cin >> sx >> sy;
  cin >> gx >> gy;
  sx--; sy--; gx--; gy--;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maze[i][j];
    }
  }
  
  queue<P> que;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) dist[i][j] = -1;

  que.push(P(sx, sy));
  dist[sx][sy] = 0;

  while (que.size()) {
    // キューの先頭を取り出す
    P p = que.front();
    que.pop();

    // ゴールなら終了
    if (p.first == gx && p.second == gy) {
        break;
    }

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' &&
          dist[nx][ny] == -1) {
        que.push(P(nx, ny));
        dist[nx][ny] = dist[p.first][p.second] + 1;
      }
    }
  }

  cout <<  dist[gx][gy] << endl;
  return 0;
}