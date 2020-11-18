N = int(input())
A = list(map(int, input().split()))
# Sは累積和、Pは今の座標、Dはその時点で最大どこまで進むか
S = [0] * N
P = [0] * N
D = [0] * N

P[0] = A[0]
S[0] = A[0]
for i in range(1, N):
    S[i] += S[i - 1] + A[i]
    P[i] = P[i - 1] + S[i]

D = [0] * N
D[0] = S[0]
for i in range(N):
    D[i] = max(D[i - 1], S[i])

ans = max(A[0], 0)
for i in range(N - 1):
    ans = max(ans, P[i] + max(D[i], 0))
ans = max(ans, max(P))
#print(P, S, D)
print(ans)
