D, N = map(int, input().split())
print(100 ** D * N) if N < 100 else print(100**D * (N + 1))
