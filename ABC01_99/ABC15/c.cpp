#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int> > T(N, vector<int>(K));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      cin >> T[i][j];
    }
  }

  int l = pow(K, N);
  bool flag = false;
  // jは質問が何個目か、 iはbitsフラグ
  for (int i = 0; i < l; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      int cur = T[j][(i / int(pow(K, j))) % K];
      sum ^= cur;
    }
    if (sum == 0) flag = true;
  }

  if (flag)
    cout << "Found" << endl;
  else
    cout << "Nothing" << endl;
  return 0;
}