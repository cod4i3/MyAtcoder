#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int, int> P;

int main(){
    int N,M;
    cin >> N >> M;
    
    priority_queue<P, vector<P>, greater<P> > que;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        P p = make_pair(b, a);
        que.push(p);
    }

    int ans = 0;
    int cur = 0;
    while(!que.empty()){
        if(cur > que.top().second){
            que.pop();
        }else{
            cur = que.top().first;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}