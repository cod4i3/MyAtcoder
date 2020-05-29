N = int(input())
a = list(map(int, input().split()))
num = 1000
ans = 0
for i in range(1, len(a)):
    if(a[i] == a[i - 1]):
        a[i] = num
        num += 1
        ans += 1
print(ans)
