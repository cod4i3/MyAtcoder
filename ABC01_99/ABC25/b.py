N, A, B = map(int, input().split())
ans = N
for i in range(N):
    s, d = input().split()
    n = int(d)
    if (n < A): n = A
    if(n > B): n = B
    if (s == "East"): ans += n
    else: ans -= n
if (N - ans > 0): print("West", abs(N - ans))
elif (ans - N > 0): print("East", abs(N - ans))
else: print(0)