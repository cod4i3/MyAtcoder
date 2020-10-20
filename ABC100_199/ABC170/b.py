X, Y = map(int, input().split())
if(Y % 2 == 1):
    print("No")
    exit(0)
else:
    if(2 * X <= Y <= 4 * X):
        print("Yes")
        exit(0)
    else:
        print("No")
        exit(0)