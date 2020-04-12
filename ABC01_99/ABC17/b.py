x = list(input())
l = ['c', 'h', 'o', 'k', 'u']
f = 1
for i in range(len(x)):
    if (i == len(x) - 1 and x[i] == 'c'): f = -1
    elif (i == 0 and x[i] == 'h'): f = -2
    else:
        if (x[i] == 'c' and x[i + 1] != 'h'): f = -3
        elif(x[i] == 'h' and x[i - 1] != 'c'): f = -4
        elif (x[i] not in l): f = -5
        else: pass
print('YES') if f > 0 else print('NO')