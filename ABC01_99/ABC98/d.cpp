#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  vector<ll> cum(N);
  vector<ll> xum(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cum[0] = xum[0] = 0;
  for (int i = 1; i < N; i++) {
    cum[i] = cum[i - 1] + A[i];
    xum[i] = xum[i - 1] ^ A[i];
  }

  int res = N + 1;
  int l = 0, r = 0, sum = 0, xsum = 0;
  int ans = 0;
  while(true){
      while(r < N && sum < (1 << 20)){
          sum += cum[r++];
          xsum ^= xum[r++];
          if(sum == xsum) ans++;
      }

      res = min(res, r - l);
      sum -= cum[l++];
      xsum ^= xum[l++];
      if(sum == xsum) ans++;
  }
}