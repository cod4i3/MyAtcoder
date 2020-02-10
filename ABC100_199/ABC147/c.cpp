#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
using Graph = vector<vector<pair<int, bool> > >;

int main() {
  int N;
  cin >> N;
  Graph A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int x;
      bool y;
      cin >> x >> y;
      A[i].push_back(make_pair(x - 1, y));
    }
  }

  int ans = 0;
  // ビットが立ってる時正直者
  for (int mask = 0; mask < (1 << N); mask++) {
    // 矛盾があるかないか
    bool OK = true;
    for (int i = 0; i < N; i++) {
      // i人目を正直者とした場合を考える（不親切なら発言内容はどうでもいい）
      if ((1 << i) & mask) {
        for (pair<int, bool> P : A[i]) {
          if (((1 << P.first) & mask) > 0 && P.second == 0) OK = false;
          if (((1 << P.first) & mask) == 0 && P.second == 1) OK = false;
        }
      } else
        continue;
    }

    if (OK) {
      // maskを2進数に、向きは反対になっているがこれでもOKのはず
      string bits = "";
      for (int i = 0; i < N; i++) {
        if ((1 << i) & mask)
          bits += '1';
        else
          bits += '0';
      }
      int sum = count(bits.begin(), bits.end(), '1');
      ans = max(sum, ans);
    }
  }

  cout << ans << endl;
  return 0;
}