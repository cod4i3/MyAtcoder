N = int(input())
s = [input() for _ in range(N)]
for i in range(N):
    s[i] = s[i][::-1]
s.sort()
for i in range(N):
    print(s[i][::-1])
