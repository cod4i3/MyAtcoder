#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;

  // dp[l][r] = 区間(l, r)に含まれる列車の本数
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
  vector<vector<bool>>seen(N + 1, vector<bool>(N+1, false));
  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    dp[l - 1][r - 1]++;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      dp[i][j + 1] += dp[i][j];
    }
  }

  for(int i=N; i>0; i--){
    for(int j=0; j<N;j++){
      dp[i-1][j] += dp[i][j];
    }
  }


  vector<int> ans(Q);
  for(int i=0; i<Q; i++){
     int p, q;
     cin >> p >> q;
     ans[i] = dp[p - 1][q - 1];
  }

  for(int i=0; i<Q; i++){
    cout << ans[i] << endl;
  }
  return 0;
}