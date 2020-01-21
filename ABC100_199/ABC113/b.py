N = int(input())
T, A = map(int, input().split())
H = list(map(int, input().split()))
t = [(T - H[i] * 0.006) for i in range(N)]
cur = 100000
for i in range(N):
    if (abs(t[i] - A) < cur): cur, ans = abs(t[i] - A), i + 1
print(ans)
