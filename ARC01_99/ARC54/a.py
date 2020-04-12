L, X, Y, S, D = map(int, input().split())
if (X >= Y):
    if (D > S): print((D - S) / (X + Y))
    else: print((L - S + D) / (X + Y))
else:
    if (D > S): print(min((D - S) / (X + Y), (L - D + S) / (Y - X)))
    else: print(min((S - D) / (Y - X), (L - S + D) / (X + Y)))