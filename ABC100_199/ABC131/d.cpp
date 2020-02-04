#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll> > W;
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    W.emplace_back(make_pair(b, a));
  }
  sort(W.begin(), W.end());
  ll time = 0;
  for (int i = 0; i < N; i++) {
    time += W[i].second;
    if (time > W[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}