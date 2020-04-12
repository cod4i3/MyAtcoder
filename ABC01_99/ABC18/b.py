S = input()
N = int(input())
ans = S
for i in range(N):
    l, r = map(int, input().split())
    l, r = l - 1, r - 1
    ans = ""
    for j in range(l): ans += S[j]
    for j in range(r, l - 1, -1): ans += S[j]
    for j in range(r + 1, len(S)): ans += S[j]
    S = ans
print(ans)
