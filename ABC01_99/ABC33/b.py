N = int(input())
S, P = [" "] * N, [0] * N
for i in range(N):
    s, p = input().split()
    S[i], P[i] = s, int(p)
for i in range(N):
    if (sum(P) / 2 < P[i]):
        print(S[i])
        exit(0)
print('atcoder')
