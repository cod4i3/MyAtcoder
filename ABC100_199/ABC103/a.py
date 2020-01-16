a = list(map(int, input().split()))
print(abs(a[0] - a[1])+abs(a[1]-a[2])+abs(a[2]-a[0])-(max(a)-min(a)))