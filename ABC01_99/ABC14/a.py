a = int(input())
b = int(input())
if (b > a): print(abs(b - a))
else:
    if (a == b): print(0)
    else:
        print((a // b + 1) * b - a)