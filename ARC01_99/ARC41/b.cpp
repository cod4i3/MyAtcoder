#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> b(N, vector<int>(M, 0)), a(N, vector<int>(M, 0));

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      b[i][j] = int(s[j] - '0');
    }
  }

  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < M - 1; j++) {
      if (b[i - 1][j] > 0) a[i][j] = b[i - 1][j];
    }

    for (int j = 1; j < M - 1; j++) {
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (a[i][j] > 0) b[nx][ny] -= a[i][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}