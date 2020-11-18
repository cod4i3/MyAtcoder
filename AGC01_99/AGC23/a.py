from collections import Counter
N = int(input())
A = list(map(int, input().split()))
S = [0 for _ in range(N)]
S[0] = A[0]
for i in range(1, N):
    S[i] = S[i - 1] + A[i]
ans = 0
C = Counter(S)
for k in C.keys():
    if(k != 0):
        ans += C[k] * (C[k] - 1) // 2
    else:
        ans += C[k] * (C[k] + 1) // 2
print(ans)
