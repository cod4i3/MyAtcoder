#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<string, int> guide;

int main() {
  int N;
  cin >> N;
  vector<guide> G;
  vector<guide> C;
  for (int i = 0; i < N; i++) {
    string s;
    int p;
    cin >> s >> p;
    G.push_back(guide(s, p));
    C.push_back(guide(s, p));
  }

  sort(C.begin(), C.end());

  for (int i = 0; i < N - 1; i++) {
    for (int j = N - 1; j >= i + 1; j--) {
      if (C[j].first == C[j - 1].first) {
        if (C[j].second > C[j - 1].second) {
          guide tmp = C[j];
          C[j] = C[j - 1];
          C[j - 1] = tmp;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    guide c = C[i];
    for (int j = 0; j < N; j++) {
      if (c == G[j]) cout << j + 1 << endl;
    }
  }

  return 0;
}
