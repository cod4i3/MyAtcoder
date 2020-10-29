from decimal import *
deg, dis = map(Decimal, input().split())

ans = ['N', 0]
d = ['NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW', 'N']
deg /= Decimal(10)
deg -= Decimal(11.25)
for i in range(len(d)):
    if((Decimal(22.5) * i) <= deg < (Decimal(22.5) * (i + 1))):
        ans[0] = d[i]
        break


p = list(map(Decimal, ('0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6, 20000.0').split(',')))
dis = dis / Decimal(60)
dis = dis.quantize(Decimal('0.1'), rounding=ROUND_HALF_UP)
for i in range(len(p)):
    if(Decimal(p[i]) < dis): continue
    else:
        ans[1] = i
        break
if(ans[1] == 0): ans[0] = 'C'
print(ans[0], ans[1])
