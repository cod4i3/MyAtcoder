#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

// 割る数
const ll mod = (int)(1e+9) + 7;
// 逆元(inverse)、階乗（factorial),階乗*逆元(inverse * factorial)
// inv[i] は iの逆元
/*
  照明はいくつかあるが
  t = Mod/i, k=Mod%i, t*i+k = Mod
  t * i + k = 0(mod)
  t*k^(-1) + i^(-1) = 0(mod)
  i^(-1) = t*k^(-1)(mod)
  代入して inv[i] = (Mod/i) * inv(Mod%1) % Mod
*/
ll inv[200200], fact[200200], ifact[200200];

// 二項係数の計算
ll comb(int n, int k) {
  return (fact[n] * ifact[k]) % mod * ifact[n - k] % mod;
}

int main() {
  fact[0] = fact[1] = 1;
  ifact[0] = ifact[1] = 1;
  inv[1] = 1;

  // 再帰的に逆元、階乗、階乗*逆元を求めてる
  // ifact は a/b = a*(1/b) (modp)を用いてる
  // 前処理
  for (int i = 2; i < 200200; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod; 
    fact[i] = fact[i - 1] * i % mod;  // n!
    ifact[i] = ifact[i - 1] * inv[i] % mod;
  }

  int H, W, A, B;
  cin >> H >> W >> A >> B;

  long long ans = comb(H + W - 2, H - 1);

  // 確実に通る横一列を数えてる
  /*
    純粋な長方形のマス目について、左上から右下へいく行き方は、
    (縦に移動する回数＋横に移動する回数)から(横に移動する回数)の選び方(もしくは縦に移動する回数の選び方)
    ということで、
    (H−A−1+B+x)C(B+x)×(A+W−1−B−x)C(A)
  */
  for (int i = 0; i < B; i++) {
    // 縦移動
    long long u = comb(H - A - 1 + i, i);
    // 横移動
    long long v = comb(A - 1 + W - 1 - i, A - 1);
    ans = (ans - u * v % mod + mod) % mod;
  }
  printf("%lld\n", ans);

  return 0;
}