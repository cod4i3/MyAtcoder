#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> robo;
  for (int i = 0; i < N; i++) {
    int x, d;
    cin >> x >> d;
    robo.emplace_back(make_pair(x, d));
  }

  sort(robo.begin(), robo.end());
  for (int i = 0; i < N; i++) {
  }
}