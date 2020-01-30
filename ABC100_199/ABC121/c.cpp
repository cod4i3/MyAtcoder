#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll> > drink;
  for (int i = 0; i < N; i++) {
    ll A, B;
    cin >> A >> B;
    drink.push_back(make_pair(A, B));
  }

  sort(drink.begin(), drink.end());

  ll ans = 0, sum = 0;
  for (int i = 0; i < N; i++) {
    if (sum + drink[i].second >= M) {
      ans += (M - sum) * drink[i].first;
      break;
    } else {
      ans += drink[i].first * drink[i].second;
    }
    sum += drink[i].second;
  }

  cout << ans << endl;
}