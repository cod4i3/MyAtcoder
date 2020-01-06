#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX_N 101000
#define INF 10000000000
vector<ll> dp(MAX_N, INF);

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> h(N);
  for (int i = 0; i < N; i++) cin >> h[i];
  // ここだけ調整
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 0; i < N; i++) {
    for (int k = 1; k <= K; k++) {
      dp[i + k] = min(dp[i + k], dp[i] + abs(h[i + k] - h[i]));
    }
  }

  cout << dp[N - 1] << endl;
  return 0;
}