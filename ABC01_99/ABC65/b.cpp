#include <iostream>
using namespace std;
#define MAX_N 11000

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 1; i <= N; i++) cin >> a[i];
  bool seen[N];

  int cur = 1, cnt = 0;
  while (a[cur] != 2) {
    seen[cur] = true;
    cur = a[cur];
    cnt++;
    if (cnt > N) break;
  }

  if (a[cur] == 2)
    cout << cnt + 1 << endl;
  else
    cout << -1 << endl;
  return 0;
}