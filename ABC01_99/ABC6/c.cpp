#include <iostream>
using namespace std;
using ll = long long;

void no() { cout << -1 << " " << -1 << " " << -1 << endl; }

int main() {
  ll N, M;
  cin >> N >> M;
  if (N * 4 < M || N * 2 > M) {
    no();
    return 0;
  }

  //連立方程式をといた
  // 大人 X人、老人 Y人、 赤ちゃん Z人
  for (int z = 0; z <= N; z++) {
    ll x = -M + 3 * N + z;
    ll y = M - 2 * N - 2 * z;
    if (x + y + z == N && x >= 0 && y >= 0) {
      cout << x << " " << y << " " << z << endl;
      return 0;
    }
  }
  no();
}