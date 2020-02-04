#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    for(int i=1;i<S.length();i++){
        if(S[i-1] != S[i]) ans++;
    }
    cout << ans+1 << endl;
    return 0;
}