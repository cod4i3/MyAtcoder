n = int(input())
d, x = map(int, input().split())
a = [int(input()) for i in range(n)]
ans = x
for i in range(n):
    ans += int((d - 1) / a[i]) + 1
print(ans)
