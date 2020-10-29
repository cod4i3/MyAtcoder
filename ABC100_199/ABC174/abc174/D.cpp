#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int R, W;
  R = count(S.begin(), S.end(), 'R');

  int ans = 0;
  for (int i = 0; i < R; i++) {
      if(S[i] == 'W') ans += 1;
  }

  cout << ans << endl;
}