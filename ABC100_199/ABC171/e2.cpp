#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    int nor = 0;
    for(int i=0; i<N;i++) {
        cin >> a[i];
        nor ^= a[i];
    }

    for(int i=0; i<N; i++){
        cout << (nor^a[i]) << " ";
    }

    cout << endl;
    return 0;
}