N = int(input())
if not (N % 111):
    print(N)
    exit(0)
for i in range(10):
    if i * 111 < N and (i + 1) * 111 >= N: print((i + 1) * 111)
