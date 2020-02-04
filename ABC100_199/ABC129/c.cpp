#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 735477
#define MOD 1000000007
typedef long long ll;
bool broken[MAX_N];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    broken[a] = true;
  }

  vector<ll> ans(N + 1);
  ans[0] = 1;
  broken[1] ? ans[1] = 0 : ans[1] = 1;
  for (int i = 2; i < N + 1; i++) {
    ans[i] = ans[i - 1] + ans[i - 2];
    ans[i] %= MOD;
    if (broken[i]) ans[i] = 0;
  }

  cout << ans[N] % MOD << endl;
  return 0;
}