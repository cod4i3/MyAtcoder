N = int(input())
S = [input() for i in range(N)]
for i in range(N):
    S[i] = ''.join(sorted(S[i]))

dic = {}
for i in range(len(S)):
    if S[i] in dic: dic[S[i]] += 1
    else: dic[S[i]] = 1

ans = 0
for v in dic.values():
    ans += v * (v - 1) // 2
print(ans)
