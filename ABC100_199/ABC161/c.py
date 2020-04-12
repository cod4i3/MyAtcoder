from fractions import gcd
N, K = map(int, input().split())
if (N > K):
    N = N % K
print(min(N, K - N))
exit(0)