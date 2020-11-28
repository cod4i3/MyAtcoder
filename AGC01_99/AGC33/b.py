S = input()
S = S.replace("BC", "X")
N = len(S)

res, ans = 0, 0
for i in range(N):
  if(S[i] == 'A'): res += 1
  elif(S[i] == 'X'): ans += res
  else: res = 0
print(ans)