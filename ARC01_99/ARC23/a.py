def p(y, m, d):
    return 365 * y + y // 4 - y // 100 + y // 400 + (306 * (m + 1)) // 10 + d - 429


y = int(input())
m = int(input())
d = int(input())
if (m == 1 or m == 2):
  m, y = m + 12, y - 1
print(p(2014, 5, 17) - p(y, m, d))