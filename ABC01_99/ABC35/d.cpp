#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void white(int H, int W, vector<string> &S, vector<vector<bool>> seen) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (seen[i][j]) continue;
      seen[i][j] = true;
      if (S[i][j] == '.') {
        for (int n = 0; n < 8; n++) {
          int nx = j + dx[n];
          int ny = i + dy[n];
          if (nx >= 0 && nx < W && ny >= 0 && ny < H && S[ny][nx] == '#') {
            S[ny][nx] = '.';
            seen[ny][nx] = true;
          }
        }
      }
    }
  }
}

void black(int H, int W, vector<string> &S, vector<vector<bool>> seen) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (seen[i][j]) continue;
      seen[i][j] = true;
      if (S[i][j] == '#') {
        for (int n = 0; n < 8; n++) {
          int nx = j + dx[n];
          int ny = i + dy[n];
          if (nx >= 0 && nx < W && ny >= 0 && ny < H && S[ny][nx] == '.') {
            S[ny][nx] = '#';
            seen[ny][nx] = true;
          }
        }
      }
    }
  }
}

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> S(H), S2(H);
  vector<string> ans(H);
  vector<vector<bool>> seen(H, vector<bool>(W, false));
  for (int i = 0; i < H; i++) cin >> S[i], S2[i] = S[i];

  white(H, W, S, seen);
  for (int i = 0; i < H; i++) ans[i] = S[i];
  black(H, W, S, seen);

  for (int i = 0; i < H; i++) {
    if (S[i] != S2[i]) {
      cout << "impossible" << endl;
      return 0;
    }
  }

  cout << "possible" << endl;
  for (int i = 0; i < H; i++) cout << ans[i] << endl;
  return 0;
}