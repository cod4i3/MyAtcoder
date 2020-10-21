#include<iostream>
using namespace std;

int main(){
    int N, K, X, Y, ans;
    cin >> N >> K >> X >> Y;
    if(N >= K) ans = X*K + Y*(N-K);
    else ans = X*N;
    cout << ans << endl;
    return 0;
}