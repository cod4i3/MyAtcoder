n = int(input())
ans = n
t = n + 1
l = 0
mid = 0
r = n
if(n == 2 or n == 1):
  print(1)
  exit(0)
while(abs(r - l) > 1):
  mid = (r + l) // 2

  s = ((mid) * (mid + 1)) // 2
  if(s > t):
    r = mid
  else:
    l = mid

print(n + 1 - l)