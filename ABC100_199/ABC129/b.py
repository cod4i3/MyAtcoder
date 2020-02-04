N = int(input())
W = list(map(int, input().split()))
W1, W2 = 0, sum(W)
ans = sum(W)
for i in range(N):
    W1 += W[i]
    W2 -= W[i]
    ans = min(ans, abs(W2 - W1))
print(ans)
