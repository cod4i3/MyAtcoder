W, H, x, y = map(float, input().split())
print('{:.10f}'.format((W * H) / 2), end=" ")
print(1) if(x == W / 2 and y == H / 2) else print(0)
