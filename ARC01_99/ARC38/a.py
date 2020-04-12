N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
s, g = 0, 0
flag = True
for i in range(len(A)):
    if (flag):
        s += A[0]
        A.pop(0)
    else:
        g += A[0]
        A.pop(0)
    flag ^= 1
print(s)