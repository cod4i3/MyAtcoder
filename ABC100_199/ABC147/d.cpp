#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {
  ll N;
  cin >> N;
  vector<ll> A;
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
    sum += a;
  }

  ans = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      ans += A[i] ^ A[j];
    }
  }
  cout << ans << endl;
}