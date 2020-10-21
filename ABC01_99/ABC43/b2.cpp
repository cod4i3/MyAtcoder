#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<char> S(0);
    string str;
    cin >> str;
    for(int i=0; i<str.length(); i++){
        if(str[i] == 'B'){
            if(S.size() != 0){
                S.pop_back();
            }
        }else{
            S.push_back(str[i]);
        }
    }
    for(int i=0; i<S.size();i++){
        cout << S[i];
    }
    cout << endl;
    return 0;
}