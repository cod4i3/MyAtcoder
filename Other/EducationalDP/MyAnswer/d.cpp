#include <iostream>
#include <vector>
#define MAX_W 735477
using namespace std;
using ll = long long;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> w(N + 1);
  vector<ll> v(N + 1);
  for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
  vector<vector<ll> > dp(N + 1, vector<ll>(MAX_W));
  for (int i = 1; i <= N; i++) {
  }
}