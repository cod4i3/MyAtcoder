
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct UnionFind {
  vector<int> par;
  explicit UnionFind(int n) : par(n, -1) {}

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool same(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;

    if (par[x] > par[y]) {
      int tmp = x;
      x = y;
      y = tmp;
    }

    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

vector<vector<int>> G;
// 深さ優先探索
void dfs(int v, vector<bool> &seen) {
  if (seen[v]) return;
  seen[v] = true;  // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;  // next_v が探索済だったらスルー
    dfs(next_v, seen);              // 再帰的に探索
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;

  UnionFind tree(N);
  vector<int> C(N);
  vector<vector<int>> G(N + 1, vector<int>(N + 1, 0));
  G.resize(N);
  for (int i = 0; i < N; i++) G[i].resize(N);
  vector<bool> seen(N, false);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }

  vector<int> ans;
  for (int i = 0; i < Q; i++) {
    int p, a, b;
    cin >> p >> a >> b;
    p--, a--, b--;

    if (p == 0) {
      if (!tree.same(a, b)) {
        G[a].emplace_back(b);
        G[b].emplace_back(a);
      }
      tree.merge(a, b);
    } else {
      
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
