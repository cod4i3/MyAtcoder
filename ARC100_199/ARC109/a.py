a, b, x, y = map(int, input().split())
if(a == b): print(x)
elif(a > b):
  ans = x + min(2*x, y) * ((a - 1) - b)
  print(ans)
else:
  ans = x + min(2 * x, y) * (b - a)
  print(ans)