E = list(input().split())
B = input()
L = list(input().split())
cnt = 0
bonus = 0
for i in range(6):
    if (L[i] in E): cnt += 1
if (cnt == 5 and B in L):
    print(2)
    exit(0)
if (cnt == 6):
    print(1)
    exit(0)
if (cnt >= 3): print(8 - cnt)
else: print('0')
exit(0)
