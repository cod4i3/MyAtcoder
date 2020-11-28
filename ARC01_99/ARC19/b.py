A = input()
N = len(A)
if(N % 2 == 0 and A[:N//2] == A[N//2:][::-1]):
  print(25*N)
  exit(0)
if(N % 2 and A[:N//2] == A[N//2 + 1:][::-1]):
  print(25*(N - 1))
  exit(0)

if(N % 2 == 0):
  s = A[:N//2]
  t = A[N//2:][::-1]
else:
  s = A[:N//2]
  t = A[N//2 + 1:][::-1]

cnt = 0
for i in range(len(s)):
  if(s[i] != t[i]): cnt += 1
if(cnt >= 2):
  print(25 * N)
  exit(0)

if(cnt == 1):
  print(25 * (N - 2) + 24 * 2)