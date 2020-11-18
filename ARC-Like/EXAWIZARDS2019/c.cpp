#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
int main(){
    int N, Q;
    cin >> N >> Q;

    string s;
    cin >> s;

    vector<vector<int>> G(26);
    char c;
    for(int i=0; i<N; i++){
        char c = s[i];
        G[c - 'A'].emplace_back(i);
    }

    vector<int> res(26, 0);
    vector<pair<int, int>> D;
    for(int i=0; i<N; i++) D[i] = {0, 0};
    for(int i=0; i<N; i++){
        char t, d;
        cin >> t >> d;
        if(d == 'L') res[t - 'A'] -= 1;
        else res[t - 'A'] += 1;
        
    }
}