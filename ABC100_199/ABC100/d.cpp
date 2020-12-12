#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

bool compare_cake(vector<ll> a, vector<ll> b) {
  return a[0] + a[1] + a[2] > b[0] + b[1] + b[2];
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<ll>> cake(N, vector<ll>(3));
  for (int i = 0; i < N; i++) {
    cin >> cake[i][0] >> cake[i][1] >> cake[i][2];
  }

  ll resx, resy, resz, ans = 0;
  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 2; y++) {
      for (int z = 0; z < 2; z++) {
        resx = 0, resy = 0, resz = 0;
        for (int i = 0; i < N; i++) {
          if (x) cake[i][0] *= -1;
          if (y) cake[i][1] *= -1;
          if (z) cake[i][2] *= -1;
        }
        sort(cake.begin(), cake.end(), compare_cake);
        for (int i = 0; i < M; i++) {
          resx += cake[i][0];
          resy += cake[i][1];
          resz += cake[i][2];
        }

        ans = max(ans, abs(resx) + abs(resy) + abs(resz));

        for (int i = 0; i < N; i++) {
          if (x) cake[i][0] *= -1;
          if (y) cake[i][1] *= -1;
          if (z) cake[i][2] *= -1;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}