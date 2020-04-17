#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  map<ll, int> mp;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
    mp[a[i]] = 0;
  }

  int num = 0;
  for (auto x : mp) {
    mp[x.first] = num;
    num++;
  }

  for (int i = 0; i < N; i++) {
    cout << mp[a[i]] << endl;
  }

  return 0;
}
