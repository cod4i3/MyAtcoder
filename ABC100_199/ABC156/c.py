N = int(input())
X = list(map(int, input().split()))
ans = 0
num = sum(X) // N
if (sum(X) / N - sum(X) // N >= 0.5): num += 1
for i in range(len(X)):
    ans += (X[i] - num) ** 2
print(ans)
