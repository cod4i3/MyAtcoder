#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> A;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
  int H, W;
  cin >> H >> W;

  A.resize(H);
  vector<vector<bool>> seen(H, vector<bool>(W, false));
  for (int i = 0; i < H; i++) cin >> A[i];

  queue<pair<int, int>> que;
  int sum = 0;
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A[i][j] == '#') {
        que.push({i, j});
        seen[i][j] = true;
        sum++, cnt++;
      }
    }
  }

  int ans = 0, res = 0;
  while (!que.empty()) {
    if (sum == H * W) break;
    res = 0;
    for (int i = 0; i < cnt; i++) {
      pair<int, int> p = que.front();
      que.pop();

      int y = p.first, x = p.second;
      for (int j = 0; j < 4; j++) {
        int ny = y + dy[j], nx = x + dx[j];
        if (0 <= ny && ny < H && 0 <= nx && nx < W && !seen[ny][nx]) {
          seen[ny][nx] = true;
          A[ny][nx] = '#';
          sum++, res++;
          que.push({ny, nx});
        }
      }
    }
    cnt = res;
    ans++;
  }

  cout << ans << endl;
  return 0;
}