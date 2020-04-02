N = int(input())
ans = 100 * (N // 10)
N -= 10 * (N // 10)
print(ans + min(15 * N, 100))
