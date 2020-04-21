from fractions import gcd
from math import sqrt


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


def main():
    A, B = map(int, input().split())
    C = gcd(A, B)
    if (A == 1 or B == 1):
        print(1)
        exit(0)
    if (C == 1):
        print(1)
        exit(0)
    arr = factorization(C)
    # print(arr)
    print(len(arr) + 1)


if __name__ == "__main__":
    main()
