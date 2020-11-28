N, K = map(int, input().split())
A = list(map(int, input().split()))
if(K in A):
  print("POSSIBLE")
  exit(0)
if(K > max(A)):
  print("IMPOSSIBLE")
  exit(0)
from math import gcd
r = gcd(A[0], A[1])
for i in range(N): r = gcd(r, A[i])
if(K % r): print("IMPOSSIBLE")
else: print("POSSIBLE")
