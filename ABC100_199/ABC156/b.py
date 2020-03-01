N, K = map(int, input().split())
ans = ""
while (N):
    ans += str(N % K)
    N //= K
print(len(ans))
