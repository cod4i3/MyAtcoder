#include <algorithm>
#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int N, M, K, p, q, cnt;

struct UnionFind {
  // 各ノードの親と、そのコンストラクタ（初期値は全部-1)
  vector<int> par;
  explicit UnionFind(int n) : par(n, -1) {}

  // 根を返す。mergeで初期化され各ノードの根は自分自身となる。
  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  // 根が同じかどうか
  bool same(int x, int y) { return root(x) == root(y); }

  // 結合
  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;

    // swap(x, y)。 vector以外のライブラリに拠らない構成にしてみた
    // swap使いたいなら #include<utility> 忘れないように
    if (par[x] > par[y]) {
      int tmp = x;
      x = y;
      y = tmp;
    }

    // 根を統一する。
    // 根はサイズを保存しており、根以外は親のindexを持つ
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  cin >> N >> M >> K;
  vector<int> ans(N, -1);
  UnionFind uf(N);
  // 友人とブロック関係が同一になることがないからこうしたが
  // その条件がない場合はsetの方がいいかもしれない
  vector<vector<int>> minus(N, vector<int>(0));
  FOR(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    minus[a].emplace_back(b);
    minus[b].emplace_back(a);
    uf.merge(a, b);
  }

  FOR(i, K) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    if (!uf.same(c, d)) continue;
    minus[c].emplace_back(d);
    minus[d].emplace_back(c);
  }

  FOR(i, N) ans[i] = uf.size(i) - minus[i].size() - 1;

  FOR(i, N - 1) cout << ans[i] << " ";
  cout << ans[N - 1] << endl;
  return 0;
}