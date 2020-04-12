N, A, B = map(int, input().split())
S = [int(input()) for i in range(N)]
if max(S) - min(S) == 0: print(-1); exit(0)
P = B / (max(S) - min(S))
Q = A - (P / N) * sum(S)
print(P, Q)
