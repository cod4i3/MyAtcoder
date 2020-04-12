A, B, C = map(int, input().split())
if (C != A + B and C != A - B): print('!')
else:
    if (A == 0 or B == 0): print('?')
    elif (C == A + B): print('+')
    else: print('-')