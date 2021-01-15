def main():
    N = int(input())
    A = [float(input()) for i in range(N)]
    #丸めないとダメらしい
    #おそらくどこかに小数点が残ってた？
    A = [int(round(A[i] * (10 ** 9))) for i in range(N)]
    cnt = [[0] * 20 for _ in range(20)]
    for i in range(N):
        res = A[i]
        two, five = 0, 0
        while(res % 2 == 0 and two < 18):
            res, two = res // 2, two + 1
        while(res % 5 == 0 and five < 18):
            res, five = res // 5, five + 1
        cnt[two][five] += 1

    ans = 0
    for i in range(20):
        for j in range(20):
            for k in range(20):
                for l in range(20):
                    if(i + k < 18 or j + l < 18): continue
                    if(i == k and j == l): ans += cnt[i][j] * (cnt[i][j] - 1)
                    else: ans += cnt[i][j] * cnt[k][l]
    print(ans // 2)


if __name__ == "__main__":
    main()
