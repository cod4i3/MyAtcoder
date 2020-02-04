N, L = map(int, input().split())
sub = 10000
ans = 0
for i in range(N):
    ans += L + i
    sub = min(abs(sub), abs(L + i))
    if (L + i) < 0: sub *= - 1
print(ans - sub)
