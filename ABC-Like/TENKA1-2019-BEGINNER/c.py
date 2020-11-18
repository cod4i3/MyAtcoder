N = int(input())
S = input()
b, w = S.count('#'), S.count('.')
ans = 2 * 10**6
cnt = 0
for i in range(N):
    if(S[i] == '#'):
        ans = min(ans, w - cnt)
        break
    cnt += 1
cnt = 0
for i in range(N - 1, -1, -1):
    if(S[i] == '.'):
        ans = min(ans, b - cnt)
        break
    cnt += 1
if(w == N): ans = 0

print(ans)
