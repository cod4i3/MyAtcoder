#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100100
#define MAX_M 100100

// ACしたかどうか
bool seen[MAX_N];

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> p(MAX_N);
  string s[MAX_M];
  int ac = 0;
  vector<int> wa(MAX_N, 0);
  for (int i = 0; i < M; i++) cin >> p[i] >> s[i];
  for (int i = 0; i < M; i++) {
    int P = p.at(i);
    if (seen[P]) continue;
    if (s[i] == "AC") {
      // AC済みにする
      seen[P] = true;
      ac++;
    }
    if (s[i] == "WA") wa[P] += 1;
  }

  // WAの合計
  int sum = 0;
  for (int i = 0; i < N + 1; i++) {
    if (seen[i]) sum += wa[i];
  }
  cout << ac << ' ' << sum << endl;
  return 0;
}
