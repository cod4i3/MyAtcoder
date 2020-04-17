#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N % 100 == 7 || (N / 10) % 10 == 7 || N / 100 == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}