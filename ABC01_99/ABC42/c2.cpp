#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> D(K);
    for(int i=0; i<K; i++) cin >> D[i];
    
    while(true){
        int ans = N;
        bool flag = true;
        while(ans){
            for(int i=0; i<K; i++){
                if(ans % 10 == D[i]) flag = false;
            }
            ans /= 10;
        }
        if(flag) break;
        N++;
    }

    cout << N << endl;
    return 0;
}