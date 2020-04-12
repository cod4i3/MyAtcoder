#include <stdio.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  char C, c;
  cin >> C >> c;
  if (int(C) - int(c) == ('A' - 'a'))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
