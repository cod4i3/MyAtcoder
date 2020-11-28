#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<ll>> cake(N, vector<ll>(3));
  for (int i = 0; i < N; i++) {
      cin >> cake[i][0] >> cake[i][1] >> cake[i][2];
  }

}