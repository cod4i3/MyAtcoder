a, b, k = map(int, input().split())
if k >= a:
    b = b - (k - a)
    if b <= 0: b = 0
    a = 0
else:
    a -= k
print(a, b)
