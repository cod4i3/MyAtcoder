H = int(input())
cnt, ans = 1, 0
while (H):
    H //= 2
    ans += cnt
    cnt *= 2
print(ans)