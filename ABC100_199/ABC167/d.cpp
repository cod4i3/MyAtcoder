#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 210000;
using namespace std;
using ll = long long;

int main() {
  ll N, K;

  cin >> N >> K;

  vector<ll> A(N + 1, 0);
  FOR(i, N) cin >> A[i];

  // 何番目か
  vector<int> ord(N + 1, -1);
  //　頂点の保存
  vector<int> s;

  // cは周期 lはループ前の長さ
  int c = 1, l = 0, v = 1;
  while (ord[v] == -1) {
    ord[v] = s.size();
    s.emplace_back(v);
    v = A[v - 1];
  }
  c = s.size() - ord[v];
  l = ord[v];

  if (K < l)
    cout << s[K] << endl;
  else {
    K -= l;
    K %= c;
    cout << s[l + K] << endl;
  }
  return 0;
}
