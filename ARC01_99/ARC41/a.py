x, y = map(int, input().split())
k = int(input())
print(x + k) if k < y else print(y + x - (k - y))