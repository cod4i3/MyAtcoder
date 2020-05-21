N, A, B = map(int, input().split())
for i in range(N):
    if(B != A + 1): A += 1
    elif(A != 0): A -= 1
    else: print('Borys'); exit(0)
    if(A != B - 1): B -= 1
    elif(B != N): B += 1
    else: print('Alice'); exit(0)
print('Draw')
