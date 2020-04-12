#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> S;
  int m = 0;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (!S[s])
      S[s] = 1;
    else
      S[s]++;
    m = max(m, S[s]);
  }

  for (auto p : S) {
    if (p.second == m) cout << p.first << endl;
  }
  return 0;
}