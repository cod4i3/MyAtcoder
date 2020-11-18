#include<iostream>
#include<vector>
using namespace std;

vector<bool> seen(100500, false);
vector<vector<int>> C;

void dfs(int v){
    if(seen[v]) return;
    seen[v] = true;

    for(auto next_v: C[v]){
        if(seen[next_v]) continue;
        dfs(next_v);
    }
    return;
}

int main(){
    int N, M;
    cin >> N >> M;
    C.resize(N);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        C[a].emplace_back(b);
        C[b].emplace_back(a);
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        if(seen[i]) continue;
        dfs(i);
        ans++;
    }

    cout << ans - 1 << endl;
    return 0;
}