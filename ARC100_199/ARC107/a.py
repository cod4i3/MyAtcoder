MOD = 998244353
a, b, c = map(int, input().split())
A = (a * (a + 1) // 2) % MOD
B = (b * (b + 1) // 2) % MOD
C = (c * (c + 1) // 2) % MOD
print( (A*B*C) % MOD)
