#include <iostream>
using namespace std;

int main(){
    int n[3];
    int five = 0, seven = 0;
    for(int i=0;i<3;i++) {
        cin >> n[i];
        if(n[i] == 5) five++;
        if(n[i] == 7) seven++;
    }
    if(five == 2 && seven == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}