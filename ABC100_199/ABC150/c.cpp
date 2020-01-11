#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> P;
  vector<int> Q;
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    P.push_back(p);
  }

  for (int i = 0; i < N; i++) {
    int q;
    cin >> q;
    Q.push_back(q);
  }

  vector<int> ans;
  for (int i = 0; i < N; i++) ans.push_back(i + 1);

  ll pcnt = 0, qcnt = 0;
  bool pflag = false, qflag = false;
  ll a = 1, b = 1;
  ll cnt = 0;
  do {
    cnt++;
    for (int i = 0; i < N; i++) {
      if (ans[i] == P[i]) pcnt++;
      if (ans[i] == Q[i]) qcnt++;
    }
    if (pcnt == N) {
      pflag = true;
      a = cnt;
    }

    if (qcnt == N) {
      qflag = true;
      b = cnt;
    }
    pcnt = 0, qcnt = 0;
    if (pflag && qflag) break;
  } while (next_permutation(ans.begin(), ans.end()));

  cout << abs(a - b) << endl;
  return 0;
}