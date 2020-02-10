#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> l(N);
  for (int i = 0; i < N; i++) cin >> l[i];
  sort(l.begin(), l.end());
  do {
  } while (next_permutation(l.begin(), l.end()));
}