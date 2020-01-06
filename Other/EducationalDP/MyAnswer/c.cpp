#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> a, b, c;
vector<vector<ll> > dp(101000, vector<ll>(3));

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    a.push_back(A);
    b.push_back(B);
    c.push_back(C);
  }

  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  for (int i = 0; i < N; i++) {
    dp[i + 1][0] = max(dp[i][1], dp[i][2]) + a[i];
    dp[i + 1][1] = max(dp[i][0], dp[i][2]) + b[i];
    dp[i + 1][2] = max(dp[i][0], dp[i][1]) + c[i];
  }

  cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
  return 0;
}