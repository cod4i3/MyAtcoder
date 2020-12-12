
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

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

int main() {
  ll N, M;
  cin >> N >> M;

  UnionFind tree(N);
  vector<pair<ll, ll>> vec(M);
  for (int i = 0; i < M; i++) {
   int a, b;
    cin >> a >> b;
    a--, b--;
    vec[i] = make_pair(a, b);
  }

  vector<ll> ans;
  ll res = (N - 1) * N / 2;
  for (int i = M - 1; i >= 0; i--) {
    ans.emplace_back(res);
    ll a = vec[i].first, b = vec[i].second;
    if(tree.same(a, b)) continue;
    res -= tree.size(a) * tree.size(b);
    tree.merge(a, b);
  }

  reverse(ans.begin(), ans.end());
  for(int i=0; i<M; i++) cout << ans[i] << endl;
  return 0;
}