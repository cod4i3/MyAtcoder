a, b, k = map(int, input().split())
if (a == 1 or b == 1):
    print(1)
    exit(0)
div = []
ans = 0
for i in range(1, max(a, b) + 1):
    if (a % i == 0 and b % i == 0):
        div.append(i)
div.reverse()
print(div[k - 1])
