a = list(map(int, input().split()))
a.remove(max(a))
print(int(a[0] * a[1] / 2))