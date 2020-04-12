N, K = map(int, input().split())
t = [int(input()) for _ in range(N)]
for i in range(2, N):
    if (t[i] + t[i - 1] + t[i - 2] < K):
        print(i + 1)
        exit(0)
print(-1)