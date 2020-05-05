def main():
    N = int(input())
    r = [list(map(int, input().split()))for i in range(N)]
    c = [0] * 1100000
    for i in range(N):
        c[r[i][0]] += 1
        c[r[i][1] + 1] -= 1

    s = [0] * 1100000
    s[0] = c[0]
    for i in range(1000100):
        s[i] = s[i - 1] + c[i]
    ans = max(s)
    print(ans)


if __name__ == "__main__":
    main()
