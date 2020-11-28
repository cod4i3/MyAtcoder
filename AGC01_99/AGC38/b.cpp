#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> G(N);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for(int i=0; i<N; i++){
        if(G[i].size() % 2){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout  << "YES" << endl;
    return 0;
}