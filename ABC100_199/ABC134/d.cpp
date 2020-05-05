#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1, 0);
  for (int i = 1; i <= N; i++) cin >> a[i];

  vector<int> b(N + 1, 0);
  for (int i = N; i > 1; i--) {
    int cnt = 0;
    for (int j = i; j <= N; j += i) {
      cnt += b[j];
    }
    cnt %= 2;
    if (a[i] == cnt)
      b[i] = 0;
    else
      b[i] = 1;
  }

  int sum = 0;
  for (int i = 0; i < N + 1; i++) sum += b[i];
  b[1] = (sum + a[1]) % 2;

  int cnt = 0;
  for (int i = 1; i <= N; i++)
    if (b[i]) cnt++;

  cout << cnt << endl;
  if (cnt) {
    for (int i = 1; i <= N; i++)
      if (b[i]) cout << i << " ";
    cout << endl;
  }
  return 0;
}