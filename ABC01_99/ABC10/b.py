n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
    while (a[i] >= 2 and ((a[i] - 2) % 3 == 0 or a[i] % 2 == 0)):
        a[i] -= 1
        cnt += 1
print(cnt)