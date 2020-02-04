A, B = map(int, input().split())
ans, cnt = 1, A
while (cnt < B):
    cnt += A - 1
    ans += 1
print(ans)