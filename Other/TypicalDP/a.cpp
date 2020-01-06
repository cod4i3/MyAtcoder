


















/*
#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 110
#define MAX_P 11000
vector<int> p(MAX_N);
vector<bool> dp(MAX_P, 0);
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> p[i];
  dp[0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 10000; j >= 0; --j) {
      if (dp[j] == 1) dp[p[i] + j] = 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < MAX_P; i++) {
    if (dp[i]) ans++;
  }

  cout << ans << endl;
  return 0;
}

*/