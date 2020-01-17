n, m, X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
if (min(y) > max(x)):
    if (X < min(y) and min(y) <= Y):
        print('No War')
        exit(0)
print('War')
