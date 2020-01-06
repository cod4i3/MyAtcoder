#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  ll ans = 0;
  for(int mask = 0; mask < (1<<(s.length() -1)); mask++){
      ll num = s[0] - '0';
      for(int i=0; i<s.length() -1; i++){
          if(mask & (1 << i)){
              ans += num;
              num = 0;
          }
          num = num * 10 + (s[i+1] - '0');
      }
      ans += num;
  }

  cout << ans << endl;
  return 0;
}
