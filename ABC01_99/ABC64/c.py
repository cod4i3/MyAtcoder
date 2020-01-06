N = int(input())
a = list(map(int, input().split()))
color = [0] * 9
for p in a:
    if p >= 3200: color[8] += 1
    else: color[p // 400] += 1
small = len([c for c in color[0:8] if c > 0])
big = small + color[8]
if not small: small += 1
print(small, big)
