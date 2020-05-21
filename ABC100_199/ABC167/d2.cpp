// 一般的なグラフの形で書いてみる
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  // Nは頂点の数
  ll N, K;
  cin >> N >> K;
  // 頂点、 町、　道筋
  vector<int> v(N, -1), a(N), path;
  for (auto &i : a) cin >> i, --i;
  int p = 0;
  while (v[p] == -1) {
    v[p] = path.size();
    if (v[p] == K) return cout << p + 1 << endl, 0;
    path.emplace_back(p);
    p = a[p];
  }

  int u = path.size();
  (K -= v[p]) %= u - v[p];
  cout << path[v[p] + K] + 1 << endl;
  return 0;
}