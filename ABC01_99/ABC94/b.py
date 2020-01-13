n, m, x = map(int, input().split())
a = list(map(int, input().split()))
l, r = 0, 0
for i in range(n):
    if (i < x and a.count(i)): l += 1
    if (i > x and a.count(i)): r += 1
print(min(l, r))
