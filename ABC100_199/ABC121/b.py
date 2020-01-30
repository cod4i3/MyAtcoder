N, M, C = map(int, input().split())
B = list(map(int, input().split()))
A = [[] for i in range(N)]
for i in range(N): A[i] = list(map(int, input().split()))
ans, sum = 0, 0
for i in range(N):
    sum = C
    for j in range(M):
        sum += A[i][j] * B[j]
    if (sum > 0): ans += 1
print(ans)
