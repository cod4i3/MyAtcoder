n = int(input())
ans = 100000
for i in range(400):
    for j in range(i, 400):
        if(i * j <= n): ans = min(abs(i - j) + (n - i * j), ans)
print(ans)
