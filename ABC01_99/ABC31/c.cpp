#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FORR(i, n) for (int i = n; i >= 0; i--)

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  FOR(i, N) cin >> a[i];
  vector<int> ans(N - 1, -5000);

  FOR(i, N) {
    int player1 = 0, player2 = 0;
    int opt = -5000;

    FORR(j, i) {
      player1 += a[j];
      if (player2 >= opt && i != j) {
        opt = player2;
        ans[i] = player1;
      }
      int tmp = player1;
      player1 = player2;
      player2 = tmp;
      /*
      cout << "i = " << i << " j =  " << j << endl;
      cout << "p1 = " << player1 << " p2 = " << player2 << " opt = " << opt
           << endl;
           */
    }

    player1 = 0, player2 = 0;

    FOR2(j, i + 1, N) {
      if ((j - i) % 2 == 1) {
        player1 += a[j - 1];
        player2 += a[j];
        if (player2 > opt) {
          opt = player2;
          ans[i] = player1;
        }
      }
    }
    /*
    cout << ans[i] << endl;
    cout << player1 << " " << player2 << endl;
    */
  }

  int an = -5000;
  FOR(i, N) an = max(an, ans[i]);

  cout << an << endl;
  return 0;
}