N, K = map(int, input().split())
R = list(map(int, input().split()))
R.sort()
ans = 0
for i in range(len(R) - K, len(R)):
    ans += R[i]
    ans /= 2
print(ans)