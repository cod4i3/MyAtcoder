#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> l(N);
  REP(i, N) cin >> l.at(i);
  sort(all(l));
  reverse(all(l));
  int sum = 0;
  REP(i, K) sum += l.at(i);
  cout << sum << endl;
  return 0;
}