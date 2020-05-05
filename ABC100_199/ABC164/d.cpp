#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int N = S.length();

  ll ans = 0;
  // 各modの数
  vector<ll> cnt(2020, 0);
  cnt[0] = 1;
  int p = 1;
  int cur = 0;
  for (int i = N - 1; i >= 0; i--) {
    cur = (cur + (S[i] - '0') * p) % 2019;
    ans += cnt[cur];

    // i ~ N-1文字までをnum[i]とすると

    p = (p * 10) % 2019;
    cnt[cur]++;
  }

  cout << ans << endl;
}