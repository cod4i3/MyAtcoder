Q, H, S, D = map(int, input().split())
N = int(input())
Q *= 4
H *= 2
if(N == 1): print(min(Q, H, S))
elif(N == 2): print(min(Q * 2, H * 2, S * 2, D))
else:
    ans = 0
    if(N % 2):
        N = N - 1
        ans += min(N * Q, N * H, N * S, (N // 2) * D)
        ans += min(Q, H, S)
    else:
        ans += min(N * Q, N * H, N * S, (N // 2) * D)
    print(ans)