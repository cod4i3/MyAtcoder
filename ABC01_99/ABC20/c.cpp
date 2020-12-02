#include <iostream>
#include <vector>
#define DECIMAL_DIG 17
using namespace std;
using ll = long long;
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = mod - inv[mod%i] * (mod / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k]);
}


int main() {
  int N;
  ll D;
  cin >> N >> D;

  ll X, Y;
  cin >> X >> Y;

  if (N < X / D + Y / D || (N - X / D - Y / D) % 2 || X % D || Y % D) {
    cout << 0.0 << endl;
    return 0;
  }

  COMinit();
}