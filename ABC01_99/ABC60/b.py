a, b, c = map(int, input().split())
ans = a % b
while ans != 0:
    if ans == c:
        break
    ans = (ans + a % b) % b
print('YES') if ans == c else print('NO')
