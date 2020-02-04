N = int(input())
A = list(map(int, input().split()))
div = 0
for i in range(N):
    div += 1 / A[i]
print(1 / div)
