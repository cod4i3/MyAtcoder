#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) cin >> a[i];

  vector<ll> cost(N + 1, 0);
  cost[2] = abs(a[2] - a[1]);
  for (int i = 3; i < N + 1; i++) {
    cost[i] = min(cost[i - 1] + abs(a[i] - a[i - 1]),
                  cost[i - 2] + abs(a[i] - a[i - 2]));
  }

  cout << cost[N] << endl;
  return 0;
}