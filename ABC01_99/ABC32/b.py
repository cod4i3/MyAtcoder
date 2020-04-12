s = input()
k = int(input())
ans = 0
dic = {}
for i in range(len(s)):
    if(i + k > len(s)): break
    if (not s[i: i + k] in dic):
        dic[s[i: i + k]] = 1
        ans += 1
print(ans)
