#include <iostream>
#include <queue>
using namespace std;
#define MAX_A 1010
#define MAX_B 1010

vector<vector<int> > dp(MAX_A, vector<int>(MAX_B));
int main() {
  int A, B;
  cin >> A >> B;
  vector<int> a(A), b(B);
  for (int i = 0; i < A; i++) {
    int A;
    cin >> A;
    a.push_back(A);
  }

  for (int i = 0; i < B; i++) {
    int B;
    cin >> B;
    b.push_back(B);
  }

  for(int )
}