#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 100000000;
    for(int y = a[0]; y<=a[N - 1]; y++){
        int sum = 0;
        for(int i=0; i<N; i++){
            int x = a[i];
            sum += (x-y)*(x-y);
        }
        ans = min(sum, ans);
        if(ans == 0) break;
    }
    cout << ans << endl;
    return 0;
}