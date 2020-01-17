#提出の際にmathをfractionsにする(2020/1/17現在)
from math import gcd
N, X = map(int, input().split())
x = list(map(int, input().split()))
ans = abs(X - x[0])
if (N == 1):
   print(ans)
   exit(0)
for i in range(1, len(x)):
    ans = gcd(abs(x[i] - x[i - 1]), ans)
print(ans)
