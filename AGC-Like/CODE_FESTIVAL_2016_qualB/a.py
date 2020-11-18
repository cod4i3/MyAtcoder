s = 'CODEFESTIVAL2016'
S = input()
ans = 0
for i in range(16):
  if(S[i] != s[i]): ans += 1
print(ans)