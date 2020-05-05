N = int(input())
a = list(map(int, input().split()))
a.sort()
ans, cnt = 0, 0
for i in range(3 * N - 2, -1, -2):
    cnt += 1
    ans += a[i]
    if(cnt == N): break
print(ans)
