#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> land(10);
vector<string> copyland(10);
const int dx[4] = {1,  0,  -1,  0, };
const int dy[4] = {0,  1,  0,  -1, };

void dfs(int x, int y) {
  copyland[x][y] = 'x';
  for (int k = 0; k < 4; k++) {
    int nx = x + dx[k ];
    int ny = y + dy[k ];
    if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && copyland[nx][ny] == 'o')
      dfs(nx, ny);
  }
}

int main() {
  for (int i = 0; i < 10; i++) cin >> land[i];

  int flag = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      copyland = land;
      copyland[j][i] = 'o';
      dfs(j, i);
      int cnt = 0;
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          if (copyland[k][l] == 'o') cnt++;
        }
      }
      if (cnt == 0) {
        flag = 1;
        break;
      }
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
