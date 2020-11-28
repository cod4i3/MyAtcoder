// メモ化再帰
// 更新の順序が非自明なときに使える
#include <iostream>
#include <vector>
using namespace std;

// dp[v] = 頂点vを始点としたときの最大長
vector<int> dp;
vector<vector<int>> G;

// 要は出次数0、つまりグラフの端っこで0を返す
// なので再帰的に辿ればその頂点からの最大長となる
// dp[v]は変化しないので最悪計算量はO(N)
int rec(int v){
    if(dp[v] != -1) return dp[v];

    int res = 0;
    for(auto nv: G[v]){
        res = max(res, rec(nv) + 1);
    }
    return dp[v] = res;
}

int main() {
  int N, M;
  cin >> N >> M;

  dp.resize(N, -1);
  G.assign(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].emplace_back(y);
  }

  int ans = 0;
  for (int v = 0; v < N; v++) ans = max(ans, rec(v));
  cout << ans << endl;
}