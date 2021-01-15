#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, T;
  cin >> N >> T;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // dp[i][j] = i問目までからj問選んだときの時間の総和
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
    }
  }
}