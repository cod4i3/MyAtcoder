#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> red(N), blue(N);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    red[i] = make_pair(a, b);
  }
  REP(i, N) {
    int c, d;
    cin >> c >> d;
    blue[i] = make_pair(c, d);
  }
  sort(all(red));
  sort(all(blue));

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int maxH = -1;
    int del = -1;
    int memo = -1;
    for (int j = 0; j < N; j++) {
      if (blue[i].first > red[j].first && blue[i].second > red[j].second &&
          maxH < red[j].second) {
        maxH = red[j].second;
        del = j;
        memo = i;
      }
    }

    if (del >= 0) {
      red[del].first = red[del].second = 735477;
      ans += 1;
    }
  }

  cout << ans << endl;
  return 0;
}