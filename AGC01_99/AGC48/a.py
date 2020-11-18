T = int(input())
A = "atcoder"
ans = []
for i in range(T):
  S = input()
  if(str(list(S).sort) >= A):
    ans.append(-1)
    continue
  if(S >= A):
    ans.append(0)
    continue
  cnt = 0
  for i in range(min(len(A), len(S))):
    if(A[i] == S[i]): continue
    for j in range(i, len(S)):
      cnt += S.find(A[i]) - i
      S = S[:i] + A[i] + S[i+1:]
    
  ans.append(cnt)
  print(cnt, ans)
print(ans)