N, S, T = map(int, input().split())
W = int(input())
A = [int(input()) for i in range(N - 1)]
ans = 1 if(S <= W <= T) else 0
for i in range(len(A)):
    W += A[i]
    if (S <= W and W <= T): ans += 1
print(ans)