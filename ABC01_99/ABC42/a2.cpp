#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    sort(n, n+3);
    if(n[0] == 5 && n[1] == 5 && n[2] ==7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}