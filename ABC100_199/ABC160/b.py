x = int(input())
gohyaku = (x // 500) * 1000
x %= 500
goen = (x // 5) * 5
print(gohyaku + goen)
