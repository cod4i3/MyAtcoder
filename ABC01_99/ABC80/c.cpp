#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  bool F[N][10];
  vector<vector<ll> > P(N, vector<ll>(10));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> P[i][j];
    }
  }
}