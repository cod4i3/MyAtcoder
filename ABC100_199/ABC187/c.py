N = int(input())
s = [0] * N 
for i in range(N): s[i] = input()
S = list(set(s))
l = [0] * len(S)
for i in range(len(S)):
  if(S[i][0] == '!'): l[i] = S[i][1:]
  else: l[i] = S[i]

from collections import Counter
c = Counter(l)
for w, n in c.items():
  if(n >= 2): 
    print(w)
    exit()
print('satisfiable')
