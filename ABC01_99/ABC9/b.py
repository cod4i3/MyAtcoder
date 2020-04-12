N = int(input())
A = [int(input()) for _ in range(N)]
ans = 0
for i in range(N):
    if (A[i] == max(A)): pass
    else: ans = max(ans, A[i])
print(ans)