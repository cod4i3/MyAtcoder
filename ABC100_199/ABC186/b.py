H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
m = 10000
for i in range(H):
    for j in range(W):
        m = min(m, A[i][j])
ans = 0
for i in range(H):
    for j in range(W):
        ans += (A[i][j] - m)
print(ans)
