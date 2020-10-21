#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    string S;
    cin >> S;
    vector<int> n;
    while(!S.empty()){
        n.emplace_back(S[0] - '0');
        S.erase(0, 1);
    }

    ll ans = 0;
    for(int bit=0; bit<(1<< (n.size() - 1)); bit++){
        ll res = n[0];
        for(int i=0; i<n.size()-1; i++){
            if(bit & (1<<i)){
                ans += res;
                res = 0;
            }
            res = res * 10 + n[i + 1];
        }
        ans += res;
    }

    cout << ans << endl;
    return 0;
}