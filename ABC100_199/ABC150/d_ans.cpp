
/*
 x = a(P+0.5), (a ∈ A)   aは偶数なので
 x = 2a'*(2p+1)          ただしa'=a/2
 2p+1 = Odd              なので、f(x)=xを2で割り切れる回数とすると
 f(x) = f(a')            xを2で割り切れる回数=a'を2で割り切れる回数

 半公倍数が存在する条件として
 ・(a_i)が偶数 ※半公倍数自体がこの条件を含んでいるので略しても良い
 ・全iについてf(a')が存在

 f(a') = tとして
 x/(2^t) = a'/(2^t) * (2p+1)    (tは割り切れる回数)
 x' = a'' * (2p+1)      (x' = x/2^t, a'' = a'/2^t)
 a''が奇数なので
 lcm(a'') = L , L∈Odd
 x' = L(2x+1) = L*Odd
 よって,入力を全部2^tで割り切って、その最小公倍数を求め、奇数倍の数を数えれば良い
 奇数倍の数の数え方は ceil(M'/L) = (x/a+1)/2 = (x/a)/2+0.5
 この1は天井関数を表している

 答えは ceil(M'/L) （ただし、M'=M/2^t)

 結論

*/

#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int f(int x) {
  int res = 0;
  while (x % 2 == 0) {
    x /= 2;
    res++;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  // a -> a'にしている
  REP(i, n) {
    if (a[i] % 2 == 1) {
      cout << 0 << endl;
      return 0;
    }
    a[i] /= 2;
  }

  /* a' -> a''、つまり上記で言う所の2^tで割ってる
     これをやると一々a'の最大に最小公倍数を
     合わせるとか考えることがなくなるので楽
  */
  int t = f(a[0]);
  REP(i, n) {
    if (f(a[i]) != t) {
      cout << 0 << endl;
      return 0;
    }
    a[i] >>= t;  // a[i] /= 2^t
  }
  m >>= t;

  ll l = 1;
  REP(i, n) {
    l = lcm(l, a[i]);
    if (l > m) {
      cout << 0 << endl;
      return 0;
    }
  }
  // m -> m'
  m /= l;

  /*
    これはm'以下の奇数の数、つまり
    mを最小公倍数で割った時の奇数倍を表す
    (奇数倍の数=倍数中の奇数の数を求めれば良い)
  */
  ll ans = (m + 1) / 2;
  cout << ans << endl;

  return 0;
}
