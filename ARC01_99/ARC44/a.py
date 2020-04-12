from math import sqrt
N = int(input())
flag = True
if (N == 1):
    print('Not Prime')
    exit(0)
for i in range(2, int(sqrt(N)) + 1):
    if (N % i == 0):
        flag = False
if (flag):
    print('Prime')
    exit(0)
if ((N % 10) % 2 != 0 and N  % 5 != 0):
    num = 0
    while (N):
        num += N % 10
        N //= 10
    if (num % 3 != 0):
        print('Prime')
        exit(0)
    else: print('Not Prime')
else: print('Not Prime')
