from math import gcd
N, M = map(int, input().split())
S = input()
T = input()
ans = N * M // gcd(N, M)
sdir = {}
tdir = {}
for i in range(N):
    sdir[i * (ans // N)] = S[i]
for i in range(M):
    tdir[i * (ans // M)] = T[i]

for k in sdir.keys():
    if(k in tdir.keys()): 
      if(sdir[k] != tdir[k]):
        print(-1)
        exit(0)
print(ans)
