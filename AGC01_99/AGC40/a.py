S = input()
N = len(S)
ans = [0 for _ in range(N + 1)]
l = [0 for _ in range(N + 1)]
r = [0 for _ in range(N + 1)]
for i in range(N):
    if(S[i] == '<'):
        l[i + 1] = l[i] + 1
for i in range(N, 0, -1):
    if(S[i - 1] == '>'):
        r[i - 1] = r[i] + 1
for i in range(N + 1):
  ans[i] = max(l[i], r[i])
print(sum(ans))