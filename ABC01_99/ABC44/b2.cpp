#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    string w;
    cin >> w;
    map<char, int> mp;
    for(int i=0; i<w.length(); i++){
        mp[w[i]]++;
    }
    for(auto e:mp){
        if(e.second % 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}