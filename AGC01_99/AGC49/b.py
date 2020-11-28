N = int(input())
S = list(input())
T = list(input())
ans = 0

print(S, T)
for i in range(N - 1):
    if(S[i] != T[i]):
        S[i] = str(int(S[i]) ^ 1)
        S[i + 1] = str(int(S[i + 1]) ^ 1)
        ans += 1
print(S, T)
print(ans) if(S == T) else print(-1)
