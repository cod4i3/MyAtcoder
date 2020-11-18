#include <iostream>
using namespace std;

int main() {
  string s;
  long long K;
  cin >> s >> K;
  int N = s.length();

  for (int i = 0; i < N; i++) {
    if(s[i] == 'a') continue;
    if ((s[i] - 'a') + K >= 26) {
      K -= ('z' - s[i]) + 1;
      s[i] = 'a';
    }
  }

  K %= 26;
  s[N - 1] = (((s[N - 1] - 'a') + K)) % 26 + 'a';

  cout << s << endl;
}