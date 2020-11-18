s = input()
S = list(s)
K = int(input())
S *= 2
N = len(S)
cnt = 0
for i in range(N - 1):
    if(S[i] == S[i + 1]):
        S[i + 1] = '.'
        cnt += 1
ans = cnt * (K // 2) + (cnt // 2) * (K % 2)
if(S[0] == S[-1]): 
  if(K % 2 == 0): ans += (K // 2) - 1
  else: pass
print(ans)
