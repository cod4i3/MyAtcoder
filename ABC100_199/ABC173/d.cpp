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

  pair<ll, ll> P;
  ll sum = 0;
  P.first = que.front();
  que.pop();
  P.second = que.front();
  que.pop();

  while(!que.empty()){
      swap(P.first, P.second);
  }
}