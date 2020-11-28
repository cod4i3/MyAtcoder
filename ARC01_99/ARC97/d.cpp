#include <algorithm>
#include <iostream>
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

int main() {
  int N, M;
  cin >> N >> M;

  UnionFind tree(N);
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
  }

  for(int i=0; i<M; i++){
      int x, y;
      cin >> x >> y;
      x--, y--;
      tree.merge(x, y);
  }

  int ans = 0;
  for(int i=0; i<N; i++){
      if(tree.same(p[i], p[p[i]]))  ans++;
  }

  cout << ans << endl;
  return 0;
}