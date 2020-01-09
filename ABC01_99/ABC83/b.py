N, a, b = map(int, input().split())
sum = 0
for i in range(N + 1):
    add, n = 0, i
    while (n > 0):
        add += n % 10
        n //= 10
    if (add >= a and add <= b): sum += i
print(sum)
