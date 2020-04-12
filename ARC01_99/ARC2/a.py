import datetime
def p(n):
    if(n < 10): print("0", end="")
    print("{}/".format(n), end="")

Y, M, D = map(int, input().split('/'))
ans = datetime.datetime(year=Y, month=M, day=D)
while (Y % (M * D) != 0):
    ans += datetime.timedelta(days=1)
    Y, M, D = ans.year, ans.month, ans.day
p(Y); p(M)
if(D < 10): print("0", end="")
print(D)
