N = input()
cnt = [0] * 3
if(len(N) == 1 and int(N[0]) % 3):
  print(-1)
  exit(0)
if(len(N) == 1):
  print(0)
  exit(0)
if(len(N) == 2 and (int(N[0]) + int(N[1])) % 3 and int(N[0]) % 3 and int(N[1]) % 3):
  print(-1)
  exit(0)
if(len(N) == 2 and (int(N[0]) + int(N[1])) % 3 == 0):
  print(0)
  exit(0)
if(len(N) == 2):
  print(1)
  exit(0)

res = 0
for i in range(len(N)):
  n = int(N[i])
  cnt[n % 3] += 1
  res += n 
res %= 3
if(res == 0):
  print(0)
elif( (res == 2 and cnt[2] == 0) or (res == 1 and cnt[1] == 0)):
  print(2)
else:
  print(1)