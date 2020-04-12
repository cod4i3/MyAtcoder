from math import pi
N = int(input())
R = [int(input()) for _ in range(N)]
R.sort(reverse=True)
ans, p = 0, True
for i in range(N):
    if (p): ans += R[i] ** 2
    else: ans -= R[i]**2
    p ^= 1
print(ans * pi)