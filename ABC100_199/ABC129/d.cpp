#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MAX_H 2200
#define MAX_W 2200

int main() {
  int H, W;
  cin >> H >> W;
  string S[MAX_H];
  vector<vector<int> > vert(MAX_H, vector<int>(MAX_W));
  vector<vector<int> > hori(MAX_H, vector<int>(MAX_W));

  REP(i, H) cin >> S[i];

  REP(i, H) {
    int cnt = 0, start = 0;
    REP(j, W) {
      if (S[i][j] == '.') cnt++;
      if (S[i][j] == '#') {
        REP2(k, start, j) hori[i][k] = cnt;
        cnt = 0;
        start = j;
      }
      if (j == W - 1) REP2(k, start, j + 1) hori[i][k] = cnt;
    }
  }

  REP(j, W) {
    int cnt = 0, start = 0;
    REP(i, H) {
      if (S[i][j] == '.') cnt++;
      if (S[i][j] == '#') {
        REP2(k, start, i) vert[k][j] = cnt;
        cnt = 0;
        start = i;
      }
      if (i == H - 1) REP2(k, start, i + 1) vert[k][j] = cnt;
    }
  }

  vector<vector<int> > ans(H, vector<int>(W));
  int answer = 0;
  REP(i, H) {
    REP(j, W) {
      if (S[i][j] != '#') {
        ans[i][j] = vert[i][j] + hori[i][j];
        answer = max(answer, ans[i][j]);
      }
    }
  }

  cout << answer - 1 << endl;
  return 0;
}
