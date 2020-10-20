def main():
    from math import ceil
    N = int(input())
    A, B = [0] * N, [0] * N
    l, r = 0, 0
    for i in range(N):
        A[i], B[i] = map(int, input().split())
    A.sort(), B.sort()
    # 中央値の最大値、最小値
    c_min, c_max = 0, 0
    ans = 0

    if(N % 2):
        N -= 1
        c_min = A[(N + 1) // 2]
        c_max = B[(N + 1) // 2]
        ans = c_max - c_min + 1

    else:
        N -= 1
        c_min = (A[N // 2] + A[N // 2 + 1]) / 2
        c_max = (B[N // 2] + B[N // 2 + 1]) / 2
        ans = (c_max - c_min) * 2 + 1

    print(int(ans))


if __name__ == "__main__":
    main()
