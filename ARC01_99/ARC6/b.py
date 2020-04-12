from math import ceil
N, L = map(int, input().split())
k = [list(input()) for _ in range(L + 1)]
s = 0
for i in range(len(k[-1])):
    if (k[-1][i] == 'o'): s = i
ans = ceil((s + 1) / 2)
if (N == 1): print(1); exit(0)
for i in range(L, -1, -1):
    if (i == L): continue
    if (s - 1 >= 0):
        if (k[i][s - 1] == "-"):
            s -= 2
            ans -= 1
            continue
    if ((s + 1) <= len(k[i]) - 1):
        if (k[i][s + 1] == "-"):
            s += 2
            ans += 1
            continue
print(ans)
