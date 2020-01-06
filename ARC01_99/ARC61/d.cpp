#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    for (int t = 0; t < (1 << 3); t++)
    {
        int num = s[0] - '0';
        string v;
        v += s[0];
        for (int i = 1; i < 4; i++)
        {
            if ((t >> (i - 1)) & 1){
                num += s[i] - '0';
                v += '+';
                v += s[i];
            }else{
                num -= s[i] - '0';
                v += '-';
                v += s[i];
            }
        }
        if (num == 7){
            cout << v << "=7" << endl;
            return 0;
        }
    }
}