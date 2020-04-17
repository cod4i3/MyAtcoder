N, K = map(int, input().split())
nu = N ** 3
mo = 6 * (K - 1) * (N - K) + 3 * (N - 1) + 1
print(mo / nu)