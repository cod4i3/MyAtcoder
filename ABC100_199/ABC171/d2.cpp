#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

int main(){
    int N;
    ll sum = 0;
    cin >> N;
    // 数と個数
    map<int ,int> mp;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        mp[a] += 1;
        sum += a;
    }

    int Q;
    cin >> Q;
    vector<ll> ans(Q);
    for(int i=0; i<Q; i++){
        int b, c;
        cin >> b >> c;
        sum += c * mp[b] - b * mp[b];
        mp[c] += mp[b];
        mp[b] = 0;
        ans[i] = sum;
    }

    for(int i=0; i<Q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}