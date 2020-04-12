N = int(input())
A = [int(input()) for _ in range(N)]
l = [0] * 100001
ans = 0
for i in range(N):
    if (l[A[i]] > 0): ans += 1
    l[A[i]] += 1
print(ans)
