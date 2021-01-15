T = int(input())
A = "atcoder"
ans = [0] * T
S = [input() for i in range(T)]
for i in range(T):
  if(S[i].count('a') == len(S[i])): 
    ans[i] = -1
    continue
  if(S[i] > A): continue
  for j in range(0, len(S[i])):
    if(S[i][j] != 'a'):
      s = list(S[i])
      res = []
      res.append(s[0])
      res.append(s[j])
      s.pop(j)
      s.pop(0)
      res += s
      S[i] = ''.join(res)
      if(S[i] > A): 
        ans[i] = max(j - 1, 0)
        break
      else: 
        ans[i] = j
        break
      

for i in range(T):
  print(ans[i])
