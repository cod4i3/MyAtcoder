#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int N;
int P;
int sum = 0;
void dfs(int x, int y, int cur, vector<vector<bool>> seen) {
  if (y == P / N || y == 0 || x == P % N || x == 0) {
    sum = min(sum, cur);
    return;
  }
  seen[y][x] = false;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (seen[ny][nx])
      dfs(nx, ny, cur + 1, seen);
    else
      dfs(nx, ny, cur, seen);
  }
  return;
}

int main() {
  cin >> N;
  vector<vector<bool>> seen(600, vector<bool>(600, true));
  int ans = 0;
  for (int i = 0; i < N * N; i++) {
    cin >> P, P--;
    sum = N;
    dfs(P % N, P / N, 0, seen);
    ans += sum;
    cout << ans << endl;
    seen[P / N][P % N] = false;
  }
  cout << ans << endl;
  return 0;
}