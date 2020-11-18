N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
if(sum(B) > sum(A)):
  print(-1)
  exit(0)
if(sum(B) == sum(A)):
  print(0)
C = [0] * N
for i in range(N):
  C[i] = B[i] - A[i]
if(max(C) <= 0):
  print(0)
  exit(0) 
  
C.sort(reverse=True)
res, ans = 0, 0
cnt = 0
for i in range(N):
  if(C[i] > 0): res += C[i]
  else: break
  ans += 1
C.sort()
for i in range(N):
  res += C[i]
  ans += 1
  if(res < 0 or C[i] > 0): break
print(ans)
