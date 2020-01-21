N = int(input())
num = [i for i in range(N + 1)]
pat = [0] * (N + 1)
ans = 0
if N < 10: print(N); exit(0)
for i in range(N + 1):
    if (str(num[i])[0] == str(num[i])[-1]):
        cur = num[i] // 10
        cnt = 0
        while (num[i] // 10 + 10 ** (cnt + 1) <= N):
            pat[i] = num[i] // 10 + 10 ** cnt
            cnt += 1
            pat[i] += 10**max((cnt - 2), 0)
print(pat)
