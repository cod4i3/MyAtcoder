A, B, C, D = map(int, input().split())
C -= B
while (A > 0 and C > 0):
    A -= D
    if (A <= 0): break
    C -= B
    if (B <= 0): break
print('Yes') if(C <= 0) else print('No')
