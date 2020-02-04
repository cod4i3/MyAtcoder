from math import gcd
A, B, C, D = map(int, input().split())
BdivC, BdivD = B // C, B // D
AdivC, AdivD = (A - 1) // C, (A - 1) // D
GCD = gcd(C, D)
BdivCD, AdivCD = B // ((C * D) // GCD), (A - 1) // ((C * D) // GCD)
N1 = BdivC + BdivD - BdivCD
N2 = AdivC + AdivD - AdivCD
ans = (B - (A - 1)) - (N1 - N2)
print(ans)
