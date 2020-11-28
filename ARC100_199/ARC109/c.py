N, K = map(int ,input().split())
S = input()
S += S[:pow(2, K) % N]

dp = [[0] * (N + 1) for _ in range(N)]