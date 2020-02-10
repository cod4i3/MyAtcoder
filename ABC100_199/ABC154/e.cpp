#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll rec(string &S, int D, int k = 0, bool tight = true, int sum = 0) {
  if (k == S.size()) {
    return sum == D;
  }

  int x = S[k] - '0';
  int r = tight ? x : 9;
  int res = 0;

  for (int i = 0; i <= r; i++) {
  }
}

int main() {
  string N;
  int K;
  vector<int> n;
  int dp[127][2][4];
  cin >> N >> K;
  int l = N.length();

  for (auto a : N) n.push_back(a - '0');
  dp[0][0][0] = 1;
  for (int i = 0; i < l; i++) {
  }
}