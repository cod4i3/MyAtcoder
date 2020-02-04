r, d, x = map(int, input().split())
ans = [0] * 11
ans[0] = x
for i in range(1, 11):
    ans[i] = r * ans[i - 1] - d
    print(ans[i])