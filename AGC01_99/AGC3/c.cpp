#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  map<ll, int> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]] = i;
  }

  sort(A.begin(), A.end());
  int ans = 0;
  for(int i=0; i<N; i++){
      int res = abs(i - mp[A[i]]);
      res %= 2;
      ans += res;
  }
  cout << ans / 2 << endl;
  return 0;
}