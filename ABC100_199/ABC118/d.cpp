#include <iostream>
using namespace std;
typedef long long ll;
#define MAX_N 100000
//　使えるかどうか
bool can[10];
// 消費するマッチの数
int num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll dp[MAX_N];

// まだわからない
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    can[a] = true;
  }

  for (int i = 0; i < N + 1; i++) {
    for (int j = 0; j < 10; j++) {
      if (can[j] && i - num[j] >= 0) {
        cout << " i = " << i << " j = " << j << " i - num[j] = " << i - num[j]
             << " "
             << "dp[i] = " << dp[i] << endl;
      }
    }
  }

  for (int i = 0; i < N; i++) cout << dp[i] << ' ';
  cout << endl;

  cout << dp[N] << endl;
  return 0;
}