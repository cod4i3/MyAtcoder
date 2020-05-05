N, K = map(int, input().split())
ans = [1] * N
for i in range(K):
    d = int(input())
    a = list(map(int, input().split()))
    A = list(map(lambda x: x - 1, a))
    for j in range(d):
        ans[A[j]] = 0
print(sum(ans))
