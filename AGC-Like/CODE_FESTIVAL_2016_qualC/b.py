K, T = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
s = sum(a) - a[-1]
print(max(a[-1] - s - 1, 0))