N = int(input())
s = [input() for i in range(N)]
M = int(input())
t = [input() for i in range(M)]
ans, cur = 0, 0
for i in range(N):
    ans = max(ans, s.count(s[i]) - t.count(s[i]))
print(ans)
