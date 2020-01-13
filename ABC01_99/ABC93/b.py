a, b, k = map(int, input().split())
for i in range(a, a + k):
    if(i < a or i > b): continue
    print(i)
for i in range(b - k + 1, b + 1):
    if (a <= i and i <= a + k - 1): continue
    if(i < a or i > b): continue
    print(i)
