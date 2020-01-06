#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define m0(x) memset(x, 0, sizeof(x))
#define MAX_H 60
#define MAX_W 60
int H, W;
char S[MAX_H][MAX_W];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main() {
  cin >> H >> W;
  REP(i, H) REP(j, W) cin >> S[i][j];
  int ans[MAX_H][MAX_W];
  REP(i, H) REP(j, W) ans[i][j] = 0;

  REP(i, H) {
    REP(j, W) {
      if (S[i][j] == '.') {
        REP(k, 8) {
          if (i + dx[k] >= 0 && i + dx[k] < H && j + dy[k] >= 0 &&
              j + dy[k] < W && S[i + dx[k]][j + dy[k]] == '#') {
            ans[i][j]++;
          }
        }
      }
    }
  }

  REP(i, H) {
    REP(j, W) {
      if (S[i][j] == '#')
        cout << S[i][j];
      else
        cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}