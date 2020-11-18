from decimal import *
Sx, Sy, Gx, Gy = map(Decimal, input().split())
x = (Sy * Gx + Gy * Sx)/(Gy + Sy)
print(x)