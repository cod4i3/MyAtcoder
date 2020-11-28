def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors


S, P = map(int, input().split())

l = make_divisors(P)
for i in range(len(l)):
  M = l[i]
  N = P // M
  if(N + M == S):
    print('Yes')
    exit(0)
print('No')
