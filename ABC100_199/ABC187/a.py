def S(n):
    return n % 10 + ((n // 10) % 10) + ((n // 100) % 10)

A, B = map(int, input().split())
print(max(S(A), S(B)))