N = int(input())
S = input()
K = int(input())
ans = ""
for i in range(N):
  if(S[i] == S[K - 1]): ans += S[K-1]
  else: ans += '*'
print(ans)