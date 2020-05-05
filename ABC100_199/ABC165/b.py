X = int(input())
m = 100
ans = 0
while(m < X):
    m *= 1.01
    m = int(m)
    ans += 1
print(ans)