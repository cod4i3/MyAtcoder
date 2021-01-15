N, L = map(int, input().split())
a = list(map(int, input().split()))
flag = False
s = 0
for i in range(N - 1):
  if(a[i] + a[i + 1] >= L):
    flag = True
    s = i
    break
if(not flag):
  print("Impossible")
  exit(0)
print("Possible")
for i in range(s):
  print(i + 1)
for i in range(N - 1, s, -1):
  print(i)