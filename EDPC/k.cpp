#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];

    // dp[i] = 石が残りi個の時直後の手番が勝ちかどうか
    // falseが負け、 trueが勝ち、初期状態0は負け
    vector<bool> dp(K + 1, false);
    for(int i=1; i<=K; i++){
        for(int j=0; j<N; j++){
            // 配列の範囲判定
            if(i - a[j] >= 0){
                // 負けの局面があるならそれを押し付けられるので勝ち
                if(dp[i - a[j]] == 0) dp[i] = true;
            }
        }
    }

    string ans = dp[K] ? "First" : "Second";
    cout << ans << endl;
    return 0;
}