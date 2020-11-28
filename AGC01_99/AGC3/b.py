N = int(input())
A = [int(input()) for _ in range(N)]
ans = 0
for i in range(N):
    ans += max((A[i] - 1) // 2, 0)
    if(A[i] % 2): A[i] = 1
    if(A[i] % 2 == 0 and A[i] != 0): A[i] = 2
for i in range(1, N):
    if(A[i] and A[i - 1] == 1):
        ans += 1
        A[i] -= 1
        A[i - 1] = 0
for i in range(N):
    if(A[i] == 2): ans += 1
print(ans)
