S = input()
N = len(S)
A = "keyence"
if(A in S):
  print('YES')
  exit(0)
for i in range(N):
  for j in range(i+1, N):
    if(A == S[:i] + S[j:]):
      print('YES')
      exit(0)
print('NO')
