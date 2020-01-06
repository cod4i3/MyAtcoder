#include <cmath>
#include <iostream>
typedef long long ll;
int main() {
  ll N;
  std::cin >> N;
  ll ans;
  for (ll x = 1; x * x <= N; x++) ans = x * x;

  std::cout << ans << std::endl;
}