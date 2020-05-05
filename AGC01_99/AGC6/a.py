N = int(input())
S = input()
T = input()
ans = 2 * N
for i in range(N):
    for j in range(1, N + 1):
        if (S[i:] == T[:j]):
            ans = min(ans, 2 * N - j)
print(ans)
