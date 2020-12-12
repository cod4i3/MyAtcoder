N = int(input())
ans = 1
for i in range(2, 31):
  res = i
  for j in range(2, i - 1):
    if(res % j == 0): res //= j
  ans *= res
ans += 1
print(ans)