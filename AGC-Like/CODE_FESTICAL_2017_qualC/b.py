N = int(input())
A = list(map(int, input().split()))
ans = 3 ** N
res = 1
for i in range(N):
  if(A[i] % 2): continue
  res *= 2
print(ans - res)