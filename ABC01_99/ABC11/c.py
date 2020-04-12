N = int(input())
l = [int(input()) for _ in range(3)]
if (N in l):
  print('NO')
  exit(0)
cnt = 0
while (N > 0):
    for i in range(3, 0, -1):
        if (N - i in l):
            pass
        else:
            N -= i
            break
    if (N <= 0):
        print('YES')
        exit(0)
    cnt += 1
    if (cnt == 100): break
print('NO')
