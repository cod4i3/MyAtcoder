#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  ll ans = 0;
  for (int i = 1; i <= N; i++){
      ll M = N/i;
      ans += (M*(M+1)/2)*i;
  }

  cout << ans << endl;
  return 0;
}