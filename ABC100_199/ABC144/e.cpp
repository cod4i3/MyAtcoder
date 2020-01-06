#include <math.h>
#include <stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
  int N,K;
  cin >> N >> K;
  vector<int> A,F;
  int a,f;
  for(int i=0;i<N;i++){
      cin >> a;
      A.push_back(a);
  }
  for(int i=0;i<N;i++){
      cin >> f;
      F.push_back(f);
  }

  sort(A.begin(), A.end(), greater<int>());
  sort(F.begin(), F.end());
  
  for(int i=0;i<N;i++){
      
  }
  
}