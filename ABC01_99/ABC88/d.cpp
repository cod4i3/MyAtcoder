#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> P;

int H, W;
string board[110];
int dist[110][110];
queue<P> que;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
  queue<P> que;
  que.push(P(0, 0));
  dist[0][0] = 1;
  while (!que.empty()) {
    P cur = que.front();
    que.pop();
    if (cur.first == H - 1 && cur.second == W - 1) break;
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (0 <= nx && nx < H && 0 <= ny && ny < W && board[nx][ny] != '#' &&
          dist[nx][ny] == -1) {
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
        que.push(P(nx, ny));
      }
    }
  }
  return dist[H - 1][W - 1];
}

int main() {
  cin >> H >> W;

  int cnt = 0;
  for (int i = 0; i < H; i++) {
    cin >> board[i];
    for (int j = 0; j < W; j++) {
      if (board[i][j] == '.') cnt++;
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      dist[i][j] = -1;
    }
  }

  if(bfs() > 0){
    cout << cnt - dist[H-1][W-1] << endl;
  }else{
    cout << -1 << endl;
  }
}