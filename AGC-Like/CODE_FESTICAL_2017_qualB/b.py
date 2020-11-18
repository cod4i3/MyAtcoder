N = int(input())
D = list(map(int, input().split()))
M = int(input())
T = list(map(int, input().split()))
from collections import Counter
C = Counter(D)
for i in range(M):
  if(C[T[i]] == 0):
    print('NO')
    exit(0)
  C[T[i]] -= 1
print('YES')