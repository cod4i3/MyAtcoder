l = [int(input()) for _ in range(3)]
s = l.copy()
s.sort(reverse=True)
for i in range(3):
    for j in range(3):
        if(l[i] == s[j]): print(j + 1)
