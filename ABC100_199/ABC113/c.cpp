#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#define all(x) (x).begin(), (x).end()
using namespace std;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> City[N + 1];
  int P[M], Y[M];
  for (int i = 0; i < M; i++) {
    int p, y;
    cin >> p >> y;
    City[p].push_back(y);
    P[i] = p, Y[i] = y;
  }

  for (int i = 0; i < N + 1; i++) sort(all(City[i]));

  for (int i = 0; i < M; i++) {
    auto iter = upper_bound(all(City[P[i]]), Y[i]);
    cout << setfill('0') << right << setw(6) << P[i] << setfill('0') << right
         << setw(6) << iter - City[P[i]].begin() << endl;
  }

  return 0;
}
