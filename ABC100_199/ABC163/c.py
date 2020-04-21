def main():
    N = int(input())
    ans = [0] * (N + 2)
    A = list(map(int, input().split()))
    for i in range(len(A)):
        ans[A[i] - 1] += 1
    for i in range(len(A) + 1):
        print(ans[i])


if __name__ == "__main__":
    main()
