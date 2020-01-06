#include <cstdio>
#include <iostream>
#include<string.h>
using namespace std;

int main() {
  char A[128];
  cin >> A;
  if (A[0] == 'a' && strlen(A) == 1)
    cout << -1 << endl;
  else
    cout << 'a' << endl;
  return 0;
}