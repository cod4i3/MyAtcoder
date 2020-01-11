#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll N, M;
  cin >> N >> M;

  ll ans = (N - 2) * (M - 2);
  if (ans < 0) ans *= -1;
  cout << ans << endl;
  return 0;
}