#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int H, W;

void print(int i, int j) {
  if (i == H - 1) {
    cout << i + 1 << ' ' << j + 1 << ' ';
    cout << i + 1 << ' ' << j + 2 << endl;
  } else {
    cout << i + 1 << ' ' << j + 1 << ' ';
    cout << i + 2 << ' ' << j + 1 << endl;
  }
}

int main() {
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  queue<pair<int, int>> que;
  for (int i = 0; i < H - 1; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] % 2 == 1) {
        a[i + 1][j]++;
        ans++;
        que.push(make_pair(i, j));
      }
    }
  }

  for (int j = 0; j < W - 1; j++) {
    if (a[H - 1][j] % 2 == 1) {
      a[H - 1][j + 1]++;
      que.push(make_pair(H - 1, j));
      ans++;
    }
  }

  cout << ans << endl;
  for (int i = 0; i < ans; i++) {
    pair<int, int> p;
    p = que.front();
    que.pop();
    print(p.first, p.second);
  }

  return 0;
}