#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> mp;
  for (int i = 0; i < N; i++) cin >> A[i];

  /*
  条件より
  A[j] + A[i] = j - i
  j - A[j] = i + A[i]
  となればいい(j > i)
  */

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += mp[i - A[i]];
    mp[i + A[i]]++;
  }

  cout << ans << endl;

  return 0;
}