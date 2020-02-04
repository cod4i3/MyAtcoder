A, B, C = map(int, input().split())
ans = C - (A - B)
print(ans) if ans > 0 else print(0)