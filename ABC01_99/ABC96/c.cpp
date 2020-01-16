#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  int H, W;
  cin >> H >> W;
  string canvas[H];
  REP(i, H) {
    { cin >> canvas[i]; }
  }

  REP(i, H) {
    REP(j, W) {
      bool flag = false;
      if (canvas[i].at(j) == '#') {
        int x = i, y = j, nx, ny;
        REP(k, 4) {
          int nx = x + dx[k], ny = y + dy[k];
          if (0 <= nx && nx < H && 0 <= ny && ny < W &&
              canvas[nx].at(ny) == '#')
            flag = true;
        }
      } else
        flag = true;

      if (!flag) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}