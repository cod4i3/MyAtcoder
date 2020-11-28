#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> c(N);
    for(int i=0; i<N; i++) cin >> c[i];

    int cur = 0, cnt = 0;
    for(int i=0; i<N; i++){
        if(c[i] > cur){
            cur = c[i];
            cnt++;
        }
    }

    cout << N - cnt << endl;
    return 0;
}