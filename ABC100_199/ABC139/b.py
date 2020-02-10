A, B = map(int, input().split())
ans, cnt = 0, 1
while (cnt < B):
    cnt -= 1
    cnt += A
    ans += 1
print(ans)