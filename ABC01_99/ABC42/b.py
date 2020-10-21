N, L = map(int,input().split())
S =[" " for _ in range(N)]
for i in range(N):
  S[i] = input()
S.sort()
for i in range(N):
  print(S[i], end = "")