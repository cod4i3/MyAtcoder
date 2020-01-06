#include <bitset>
#include <iostream>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
  int N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  bitset<110000> win;
  REP(i, N) if (i < K || T[i - K] != T[i] || !win[i - K]) win[i] = true;
  ll ans = 0;
  REP(i, N) if (win[i]) {
    if (T[i] == 's') ans += R;
    if (T[i] == 'p') ans += S;
    if (T[i] == 'r') ans += P;
  }

  cout << ans << endl;
  return 0;
}
