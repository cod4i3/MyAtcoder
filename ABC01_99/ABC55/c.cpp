#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll N, M;
  cin >> N >> M;
  if (2 * N >= M)
    cout << M / 2 << endl;
  else
    cout << N + (M - 2 * N) / 4 << endl;
}