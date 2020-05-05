A, B, N = map(int, input().split())
x = (N // B) * B - 1
if(x < 0): x = N
ans = (A * x) // B - A * (x // B)
print(ans)
