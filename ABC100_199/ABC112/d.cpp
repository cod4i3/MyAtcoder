#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  ll ans = 0;
  for (int i = M / N; i >= 1; i--) {
    if (M % i == 0) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}