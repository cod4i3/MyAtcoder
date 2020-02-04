S = input()
for i in range(len(S)):
    c = S[i]
    if (i % 2 == 0 and c == 'L'):
        print('No')
        exit(0)
    if (i % 2 == 1 and c == 'R'):
        print('No')
        exit(0)
print('Yes')
