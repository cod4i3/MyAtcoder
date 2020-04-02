from math import ceil
N, M = map(int, input().split())
name = input()
kit = input()
ans = 0
for i in range(26):
    c = chr(ord('A') + i)
    if (kit.count(c) != 0):
        ans = max(ans, ceil(name.count(c) / kit.count(c)))
    elif (name.count(c) and not kit.count(c)):
        print(-1)
        exit(0)
print(ans) if (ans) else print(-1)
