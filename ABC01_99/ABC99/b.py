a, b = map(int, input().split())
s = [0] * 1002
for i in range(1002):
    s[i] = s[i - 1] + i
    if (s[i - 1] - a == s[i] - b ):
        print(s[i - 1] - a)
        break
