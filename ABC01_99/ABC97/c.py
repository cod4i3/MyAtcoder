s = input()
K = int(input())
letters = []
for i in range(len(s)):
    for j in range(6):
        if(i + j > len(s)): break
        if(s[i:i + j] != ''): letters.append(s[i:i + j])
l = list(dict.fromkeys(letters))
l.sort()
print(l[K - 1])
