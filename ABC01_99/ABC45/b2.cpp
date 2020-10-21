#include<iostream>
#include<vector>
using namespace std;

int main(){
    string S[3];
    cin >> S[0] >> S[1] >> S[2];
    vector<int> L(3, 0);

    int cur = 0;
    while(true){
        string str = S[cur];
        if(str.empty()) break;
        for(int i=0; i<3; i++){
            if(str[0] == char('a' + i)){
                S[cur].erase(0,1);
                cur = i;
                break;
            }
        }
    }

    cout <<  char('A'+cur) << endl;
    return 0;
}