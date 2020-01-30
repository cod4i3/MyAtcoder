#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  bool like[N + 1][M + 1];
  for (int i = 0; i < N + 1; i++) {
    for (int j = 0; j < M + 1; j++) {
      like[i][j] = false;
    }
  }

  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int A;
      cin >> A;
      like[i][A] = true;
    }
  }

  int ans = 0;
  for (int i = 0; i < M + 1; i++) {
    int cnt = 0;
    for (int j = 0; j < N + 1; j++) {
      if (like[j][i]) cnt++;
    }
    if (cnt == N) ans++;
  }

  cout << ans << endl;
}