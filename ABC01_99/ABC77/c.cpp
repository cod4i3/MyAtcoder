#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);

  REP(i, N) cin >> A.at(i);
  REP(i, N) cin >> B.at(i);
  REP(i, N) cin >> C.at(i);

  sort(all(A));
  sort(all(B));
  sort(all(C));

  ll ans = 0;
  REP(i, N) {
    ll a = lower_bound(all(A), B[i]) - A.begin();
    ll c = C.end() - upper_bound(all(C), B[i]);

    /*
    cout << "lower_bound(all(A), B[i])=" << *pre << '\t'
         << "upper_bound(all(C), B[i])" << *after << endl;
    cout << "A.begin()=" << *A.begin() << ' ' << "C.begin()=" << *C.begin()
         << "\t\t"
         << "A.end()=" << *A.end() << ' ' << "C.end()=" << *C.end() << ' '
         << endl;
    */
    cout << "lower_bound(all(A), B[i])=" << *lower_bound(all(A), B[i])
         << " A.begin() =\t" << *A.begin() << ' ' << "C.end()=" << *C.end()
         << " upper_bound(all(C), B[i])=" << *upper_bound(all(C), B[i]) << endl;
    ans += a * c;
  }

  cout << ans << endl;
}