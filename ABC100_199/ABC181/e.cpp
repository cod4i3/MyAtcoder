#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    int N, M;
    cin >> N >> M;

    vector<ll> H(N), D(N - 1);
    for(int i=0; i<N; i++) cin >> H[i];
    for(int i=0; i<N - 1; i++){
        D[i] = H[i + 1] - H[i];
    }
}