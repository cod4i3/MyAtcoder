N, K = map(int, input().split())
p = list(map(int, input().split()))
fac = [0] * 735477
fac[0] = 1
if (N >= 1):
    for i in range(1, 1010): fac[i] = i + 1 + fac[i - 1]
# 期待値
#print(p, fac[:max(p)])
exp = [0] * 735477
for i in range(N):
    exp[i] = fac[p[i] - 1] / p[i]
# print(exp)

Ans = 0
ans = [0] * 735477
ans[0] = sum(exp[:K])
for i in range(1, N - K + 1):
    if(i + K == N + 1): break
    ans[i] = ans[i - 1] - exp[i - 1] + exp[i + K - 1]
    # print(ans[i])
    #print(exp[i: i + K])
print(max(ans))
