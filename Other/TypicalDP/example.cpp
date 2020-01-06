/*

N (1≤N≤1000) 匹のリスが一列に並んでいる。左から i 匹目のリスには、整数 ai
が書かれている。この中から何匹かのリスにぶどうをのせ、ぶどうの乗ったリスにかかれた整数が左から昇順に並んでいるようにしたい。最大何匹のリスにぶどうを乗せられるか。

*/

#include <algorithm>
#include <iostream>
using namespace std;
int a[1010];
int dp[1010];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) ans = max(ans, dp[i]);
  cout << ans << endl;

  return 0;
}




/*

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

// 無限大の値
const long long INF = 1LL << 60;

// DP テーブル
long long dp[100010];

// DP テーブル全体を初期化 (最小化問題なので INF に初期化)
for (int i = 0; i < 100010; ++i) dp[i] = INF;

// 初期条件
dp[0] = 0;

// ループ
for (int i = 0; i < N; ++i) {
  chmin(dp[なにか], dp[なにか] + なにか);
  ...
}

// 解を得て出力
cout << dp[N - 1] << endl;


*/