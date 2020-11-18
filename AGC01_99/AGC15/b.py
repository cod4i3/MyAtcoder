S = input()
N = len(S)
ans = 0
for i in range(N):
    if(S[i] == 'U'): ans += (N - (i + 1)) + 2 * i
    if(S[i] == 'D'): ans += i + 2 * (N - (i + 1))
print(ans)