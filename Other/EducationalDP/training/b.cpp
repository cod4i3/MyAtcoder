/*
最初、足場 1 にカエルがいて、ぴょんぴょん跳ねながら足場 N
へと向かいます。カエルは足場 i にいるときに

足場 i から足場 i+1 へと移動する (そのコストは |hi−hi+1|)
足場 i から足場 i+2 へと移動する (そのコストは |hi−hi+2|)
...
足場 i から足場 i+K へと移動する (そのコストは |hi−hi+K|)
のいずれかの行動を選べます。カエルが足場 1 から足場 N
へと移動するのに必要な最小コストを求めよ。
*/

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
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

const long long INF = 1LL << 60;

// 入力
int N;
long long h[110000];

// DP テーブル
long long dp[110000];

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> h[i];

  // 初期化 (最小化問題なので INF に初期化)
  for (int i = 0; i < 110000; ++i) dp[i] = INF;

  // 初期条件
  dp[0] = 0;

  // ループ
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j <= K; ++j) {
      chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }

  // 答え
  cout << dp[N - 1] << endl;
}