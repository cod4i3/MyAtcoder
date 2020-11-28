#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

// dp[i][j] = 区間[i, j)の勝者
vector<vector<int>> dp;
vector<int> hand;
vector<bool> seen;

int rec(int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (abs(r - l) <= 1) {
    dp[l][r] = hand[l];
    return dp[l][r];
  }
  int mid = (l + r) / 2;
  int suml = rec(l, mid);
  int sumr = rec(mid, r);
  if (suml == sumr) {
    dp[l][r] = suml;
  }
  // suml != sumr
  else if (suml + sumr == 3) {
    dp[l][r] = 2;
  } else if (suml + sumr == 2) {
    dp[l][r] = 0;
  } else {
    dp[l][r] = 1;
  }
  return dp[l][r];
}

int main() {
  int N, K;
  cin >> N >> K;

  string s;
  cin >> s;

  s += s.substr(0, int(pow(2, double(K))) % N);
  N = s.length();
  hand.resize(N);
  for (int i = 0; i < N; i++) {
    if (s[i] == 'R') hand[i] = 0;
    if (s[i] == 'P') hand[i] = 1;
    if (s[i] == 'S') hand[i] = 2;
  }

  dp.resize(N + 10, vector<int>(N + 10, -1));
  rec(0, N);
  if (dp[0][N] == 0) cout << 'R' << endl;
  if (dp[0][K] == 1) cout << 'P' << endl;
  if (dp[0][K] == 2) cout << 'S' << endl;

  return 0;
}