#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll gcd_n(vector<ll> &numbers){
  ll GCD;
  GCD = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    GCD = gcd(GCD, numbers[i]);
  }
  return GCD;
}

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    cout << gcd_n(A) << endl;
    return 0;
}