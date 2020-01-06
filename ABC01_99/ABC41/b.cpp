#include <iostream>
using namespace std;
typedef long long ll;
#define DIV 1000000007

int main() {
  ll A, B, C;
  cin >> A >> B >> C;

  A %= DIV;
  B %= DIV;
  C %= DIV;
  ll ans = ((A * B) % DIV) * C;
  cout << ans % DIV << endl;
}