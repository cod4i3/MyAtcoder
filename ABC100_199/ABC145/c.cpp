#include <cmath>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<pair<double, double> > p;
  for(int i=0;i<N;i++){
    double x, y;
    cin >> x >> y;
    p.emplace_back(make_pair(x,y));
  }
  sort(p.begin(), p.end());
  
  vector<int> v(N);
  for(int i=0;i<N;i++) v[i] = i;
  double ans = 0;
  do{
    double dis = 0;
    for(int i=1;i<p.size();i++){
      int b = v[i-1], n = v[i];
      double x = p[b].first -  p[n].first;
      double y = p[b].second - p[n].second;
      dis += sqrt(x*x + y*y);
    }
    ans += dis;
  }while(next_permutation(v.begin(), v.end()));

  double div = 1;
  for(int i=1;i<=N;i++)div *= i;
  
  printf("%.7f\n", ans / div);
  return 0;
}