#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#define all(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> p;
  vector<int> p2;
  REP(i, N) {
    int P;
    cin >> P;
    p.push_back(P);
    p2.push_back(P);
  }

  sort(all(p2));

  int ans = 0;
  REP(i, N) {
    if (p[i] == p2[i]) {
      ans++;
      if (!p[i + 1]) continue;
      if (p[i + 1] == p2[i + 1]) i += 1;
    }
  }

  cout << ans << endl;
  return 0;
}