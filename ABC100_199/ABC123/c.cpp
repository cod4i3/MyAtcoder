#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(5);
  for (int i = 0; i < 5; i++) cin >> A[i];
  ll ans = 4;
  ll minNum = *min_element(A.begin(), A.end());
  ll plus = N / minNum;
  if (N % minNum) plus++;
  cout << ans + plus << endl;
  return 0;
}