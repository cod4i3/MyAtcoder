N = int(input())
w = [input() for i in range(N)]
for i in range(len(w) - 1):
    if (w.count(w[i]) > 1): print('No'); exit(0)
    if (w[i][-1] != w[i + 1][0]): print('No'); exit(0)
print('Yes')
