#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int N;
  cin >> N;
  vector<int> C(N + 1, 0), S(N + 1, 0), F(N + 1, 0);
  for (int i = 0; i < N - 1; i++) cin >> C[i] >> S[i] >> F[i];

  for (int i = 0; i < N - 1; i++) {
    int t = S[i];
    for (int j = i + 1; j < N; j++) {
      t += C[j - 1];
      int start = S[j];
      if (F[j] == 0) break;
      while (t < start or t % F[j] != 0) {
        t++;
      }
    }
    cout << t << endl;
  }

  cout << 0 << endl;
  return 0;
}