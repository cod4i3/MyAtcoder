ans = 1000
N = int(input())
A = list(map(int, input().split()))
res = 0
for i in range(N - 1):
    res += ans // A[i]
    ans -= (ans // A[i]) * A[i]
    if(A[i] >= A[i + 1]):
        ans += res * A[i]
        res = 0
    else: pass
ans += res * A[-1]
print(ans)