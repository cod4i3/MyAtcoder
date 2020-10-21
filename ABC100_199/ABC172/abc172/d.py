def f(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    return len(divisors)

if __name__ == "__main__":
  N = int(input())+1
  ans = [f(k) * k for k in range(N)]
  print(sum(ans))