S = input()
li = [chr(ord('a') + i) for i in range(26)]
used = [0] * 26
dic = dict(zip(li, used))
for i in range(len(S)): dic[S[i]] = 1
if(len(S) < 26):
    for i in range(26):
        k = chr(ord('a') + i)
        v = dic[k]
        if(v == 0):
            print(S + k)
            exit(0)

if(len(S) == 26):
    for i in range(25, -1, -1):
        for j in range(26): dic[chr(ord('a') + j)] = 0
        for j in range(i): dic[S[j]] = 1
        add_c = ""
        for j in range(i + 1, 26):
            if(S[j] > S[i]):
                if(add_c == ""): add_c = S[j]
                else: add_c = min(add_c, S[j])
        if(add_c):
            print(S[:i] + add_c)
            exit(0)
print(-1)
