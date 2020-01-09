from math import sqrt
a, b = input().split()
n = int(a + b)
print('Yes') if(n / int(sqrt(n)) == int(sqrt(n))) else print('No')
