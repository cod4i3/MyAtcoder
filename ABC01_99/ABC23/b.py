N = int(input())
S = input()
if (S == 'b'):
    print(0)
    exit(0)
ac = 'b'
ans = ""
for i in range(1, N + 1):
    ans = ""
    if i % 3 == 0:
        ans += "b"
        ans += ac
        ans += "b"
    elif i % 3 == 1:
        ans += "a"
        ans += ac
        ans += "c"
    else:
        ans += "c"
        ans += ac
        ans += "a"
    if (ans == S):
        print(i)
        exit(0)
    ac = ans
print(-1)
