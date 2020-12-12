from decimal import *
from math import log
P = Decimal(input())

'''
def fx(x, P):
    res = P
    res /= Decimal(2 ** (Decimal(x) / Decimal(1.5)))
    res += x
    return res


# f'(x) = 0 となる x
x = P * Decimal(log(2))
x *= Decimal(2) / Decimal(3)
x = Decimal(log(x))
x *= 3
x /= Decimal(log(Decimal(2))) * Decimal(2)

if(x < 0): print(P)
else: print(fx(x, P))
'''

# 何故か失敗した解答
# 追記: fxを変えて3分探索にすると成功した
# 追記2: 失敗多の原因は分二分探索のときr=70にしたのが原因と考えられる
#       100にしたら通った
# f(x) = x * (P)/(2**(x/1.5))
# f'(x) = 0 となる x
def fx(x, P):
  return x + P * 2 ** (-x / Decimal(1.5))

def dx(x, P):
  res = Decimal(Decimal(log(2))/ Decimal(1.5))
  res /= Decimal(2 ** (Decimal(x) / Decimal(1.5)))
  res *= P
  res = 1 - res
  return res

l, r = Decimal(0), Decimal(100)
while(abs(r - l) > 10 ** (-10)):
  mid = (l + r) / Decimal(2)
  if(dx(mid, P) > 0):
    r = mid
  else:
    l = mid
res = (l + r) / 2
print(fx(res, P))


# 三分探索
'''
a, b = Decimal(0), Decimal(100)
l = (2 * a + b) / 3
r = (a + 2 * b) / 3
while(abs(r - l) > 10 ** (-10)):
  l = (2 * a + b) / 3
  r = (a + 2 * b) / 3
  if(fx(l, P) > fx(r, P)):
    a = l
  else:
    b = r
res = (l + r) / 2
print(fx(res, P))
'''