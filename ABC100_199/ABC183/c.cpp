#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;

  vector<vector<ll>> T(N, vector<ll>(N));
  vector<int> vec(N);
  for (int i = 0; i < N; i++) vec[i] = i;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> T[i][j];
    }
  }

  ll ans = 0;
  ll res = 0;
  do {
    res = 0;
    for (int i = 1; i < N; i++) {
      res += T[vec[i - 1]][vec[i]];
    }
    res += T[vec[N - 1]][vec[0]];
    if (res == K) ans += 1;
  } while (next_permutation(vec.begin() + 1, vec.end()));

  cout << ans << endl;
  return 0;
}