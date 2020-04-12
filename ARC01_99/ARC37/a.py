N = int(input())
m = list(map(int, input().split()))
ans = 0
for i in range(N):
    ans += max(80 - m[i], 0)
print(ans)