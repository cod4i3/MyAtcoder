#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX_N 100100
vector<ll> dp(MAX_N);

int main() {
  //入力部
  int N;
  cin >> N;
  vector<int> h;
  for (int i = 0; i < N; i++) {
    int H;
    cin >> H;
    h.push_back(H);
  }

  // ここだけ調整
  dp[1] = abs(h[1] - h[0]);
  for (int i = 0; i < N; i++) {
    dp[i + 2] =
        min(dp[i + 1] + abs(h[i + 2] - h[i + 1]), dp[i] + abs(h[i + 2] - h[i]));
  }
  cout << dp[N - 1] << endl;
  return 0;
}