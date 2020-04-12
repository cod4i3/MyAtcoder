S = input()
l = ['I', 'C', 'T']
cnt = 0
for i in range(len(S)):
    if S[i].upper() == l[cnt].upper(): cnt += 1
    if(cnt == 3):
        print("YES")
        exit(0)
print("NO")
