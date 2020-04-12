N = int(input())
S = [input() for _ in range(N)]
cnt, ans = 0, 0
for i in range(N):
    if (cnt < S.count(S[i])):
        cnt = S.count(S[i])
        ans = S[i]
print(ans)