n = int(input())
N = n
div = 0
while (N != 0):
    div += N % 10
    N //= 10
print('Yes') if n % div == 0 else print('No')
