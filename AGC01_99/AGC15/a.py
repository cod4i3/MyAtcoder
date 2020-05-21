N, A, B = map(int, input().split())
ans = (B * (N - 1) + A) - (B + A * (N - 1)) + 1
print(ans) if(ans > 0) else print(0)