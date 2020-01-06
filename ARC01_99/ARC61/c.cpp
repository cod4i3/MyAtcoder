#include<iostream>
#include<cstring>
#include<string.h>
#include<cstdio>
using namespace std;
typedef long long ll;


int main(){
    char s[12345];
    scanf("%s", s);
    int len = strlen(s);
    ll ans = 0;
    // 2^(len-1) 回す
    for(int t = 0; t < (1<<(len-1)); t++){
        ll num = s[0] - '0';  //先頭の文字を数字に変換
        for(int i=0;i<len-1;i++){
            // i bit目が立ってた時+が入る
            // 立っていなかったら10倍して次の数字が加えられる
            if( t & (1 << i)){
                ans += num;
                num = 0;
            }
            num = num * 10 + s[i+1] - '0';
        }
        ans += num;
    }
    cout << ans << endl;
    return 0;
}