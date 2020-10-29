#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int H, W;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> dist(1050, vector<int>(1050, 100000000));
int C[2], D[2];
vector<string> S;

void bfs(int y, int x) {
  deque<pair<int, int>> que;
  que.push_front({y, x});

  while (!que.empty()) {
    pair<int, int> p = que.front();
    que.pop_front();

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i], nx = p.second + dx[i];
      if (0 <= ny && ny < H && 0 <= nx && nx < W && S[ny][nx] != '#') {
        if (dist[ny][nx] <= dist[p.first][p.second]) continue;
        que.push_front({ny, nx});
        dist[ny][nx] = dist[p.first][p.second];
      }
    }

    for (int h = -2; h <= 2; h++) {
      for (int w = -2; w <= 2; w++) {
        int ny = p.first + h, nx = p.second + w;
        if (0 <= ny && ny < H && 0 <= nx && nx < W && S[ny][nx] != '#') {
          if (dist[ny][nx] <= dist[p.first][p.second] + 1) continue;
          que.push_back({ny, nx});
          dist[ny][nx] = dist[p.first][p.second] + 1;
        }
      }
    }
  }
}

int main() {
  cin >> H >> W;
  S.resize(H);
  cin >> C[0] >> C[1];
  cin >> D[0] >> D[1];
  C[0]--;
  C[1]--;
  D[0]--;
  D[1]--;
  for (int i = 0; i < H; i++) cin >> S[i];
  dist.resize(H, vector<int>(W));

  dist[C[0]][C[1]] = 0;
  bfs(C[0], C[1]);

  if (dist[D[0]][D[1]] == 100000000)
    cout << -1 << endl;
  else
    cout << dist[D[0]][D[1]] << endl;
  return 0;
}