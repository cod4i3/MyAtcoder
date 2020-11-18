N, A, B = map(int, input().split())
print(min(A, B), max(B - abs(N - A), 0))