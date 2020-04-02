#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, T;
  cin >> N >> T;
  vector<ll> a(N), b(N);
  REP(i, N) cin >> a[i] >> b[i];
  ll max_b = *max_element(all(b));
  REP(i, N) b[i] -= max_b;
  vector<pair<ll, ll> > shop(N);
  REP(i, N) shop[i] = make_pair(a[i], b[i]);

  REP(i, shop.size()) {
    if (b[i] >= T || a[i] >= T) shop.erase(shop.begin() + i);
    if (shop.empty()) {
      cout << 0 << endl;
      return 0;
    }
    if (a[i] + b[i] >= T) shop.erase(shop.begin() + i);
    if (shop.empty()) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = 0;
  int time = 0;
  vector<ll> end;
  REP(i, shop.size()) end.emplace_back(shop[i].second);
  while (true) {
    if (ans == N || shop.empty()) break;
    time++;
    for (int i = 0; i < shop.size(); i++) {
      end[i] += shop[i].first * time;
    }

    if (time + *min_element(all(end)) > T) break;
    int del = min_element(all(end)) - end.begin();
    end.erase(end.begin() + del);
    shop.erase(shop.begin() + del);
    time += *min_element(all(end));
    ans++;
  }

  cout << ans << endl;
  return 0;
}