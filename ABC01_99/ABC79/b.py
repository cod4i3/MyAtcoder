N = int(input())
L = [0] * 90
L[0], L[1] = 2, 1
for i in range(2, len(L)):
    L[i] = int(L[i - 1]) + int(L[i - 2])
print(int(L[N]))
