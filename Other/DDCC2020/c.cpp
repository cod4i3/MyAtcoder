#include <iostream>
using namespace std;
typedef long long ll;
#define MAX 210000
int dx[2] = {1, -1};
char s[310][310];
bool visited[310];
int H, W;
int cnt = 1;

void dfs(int x, int y) {
  visited[x] = true;
  s[x][y] = char(cnt);
  for (int i = 0; i < 2; i++) {
    int nx = x - dx[i];
    int ny = y;
    if (0 <= nx && nx < H && 0 <= ny && ny < W && s[nx][ny] == '#') {
      dfs(nx, ny);
    }
  }
  return;
}

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  char s[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; i < W; j++) {
      cin >> s[H][W];
    }
  }

  bool flag = false;
  for (int i = 0; i < H; i++) {
    flag = false;
    for (int j = 0; j < W; j++) {
      if (s[i][j] == '#') {
        flag = true;
        dfs(i, j);
        cnt++;
      }
    }
  }

  for (int i = 0; i < H - 1; i++) {
    if (!visited[i] && visited[i + 1]) {
      for (int j = 0; j < W; j++) {
        s[i][j] = s[i + 1][j];
      }
    }
  }

  for (int i = H - 1; i >= 1; i++) {
    if (!visited[i] && visited[i - 1]) {
      for (int j = 0; j < W; j++) {
        s[i][j] = s[i - 1][j];
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << s[i][j] << endl;
    }
  }

  return 0;
}