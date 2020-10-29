from math import sqrt
N = int(input())
l = []
for i in range(1, int(sqrt(N)) + 1):
    if(N % i == 0):
        l.append(i)
        if(i != (sqrt(N))):
            l.append(N // i)
l.sort()
for i in range(len(l)):
    print(l[i])
