#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  for (int i = 0; i < N; i++){
      cin >> A[i];
  }
  sort(A.rbegin(), A.rend());

  queue<ll> que;
  for(int i=0; i<N; i++) que.push(A[i]);

  ll ans = 0;

  queue<ll> ring;
  ring.push(que.front());
  que.pop();

  while(!que.empty()){
      ans += ring.front();
      ring.pop();
      ring.push(que.front());
      ring.push(que.front());
      que.pop();
  }

  cout << ans << endl;
  return 0;
}