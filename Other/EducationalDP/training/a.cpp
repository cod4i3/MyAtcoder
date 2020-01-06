/*
N  個の足場があって、i 番目の足場の高さは hi です。
最初、足場 1 にカエルがいて、ぴょんぴょん跳ねながら足場 N
へと向かいます。カエルは足場 i にいるときに

足場 i から足場 i+1 へと移動する (そのコストは |hi−hi+1|)
足場 i から足場 i+2 へと移動する (そのコストは |hi−hi+2|)
のいずれかの行動を選べます。カエルが足場 1 から足場 N
へと移動するのに必要な最小コストを求めよ。
*/

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// aよりbが~~~だったら、aをbに置き換えるテンプレ
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long INF = 1LL << 60;
typedef long long ll;

int N;
ll h[100010];

ll dp[100010];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> h[i];

  for (int i = 0; i < N; i++) dp[i] = INF;
  dp[0] = 0;
  for (int i = 0; i < N;i++){
    chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    if (i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[N - 1] << endl;
}
