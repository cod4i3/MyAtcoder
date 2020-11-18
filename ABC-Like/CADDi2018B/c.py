def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


def main():
    N, P = map(int, input().split())
    from collections import Counter
    C = Counter(prime_factorize(P))
    ans = 1
    for e in C.items():
        if(e[1] >= N): ans *= e[0] ** (e[1] // N)
    print(ans)


if __name__ == "__main__":
    main()
