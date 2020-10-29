#include <iostream>
using namespace std;

int main() {
  int N;
  string S, str;
  cin >> N >> S;

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    str = "";
    int A = 0, T = 0, C = 0, G = 0;
    for (int j = i; j < N; j++) {
      if (S[j] == 'A') A += 1;
      if (S[j] == 'T') T += 1;
      if (S[j] == 'C') C += 1;
      if (S[j] == 'G') G += 1;
      str += S[j];
      if(A == T && C == G) ans += 1;
    }
  }
  cout << ans << endl;
}