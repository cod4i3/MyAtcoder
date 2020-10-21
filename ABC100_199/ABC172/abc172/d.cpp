#include<iostream>
#include<vector>
using namespace std;
using ll = long long;


ll f(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res.size();
}

int main(){
    int N;
    cin >> N;
    ll ans = 0;
    vector<ll> F(N);
    for(ll k=1; k<=N; k++){
    }
    cout << ans << endl;
    return 0;
}