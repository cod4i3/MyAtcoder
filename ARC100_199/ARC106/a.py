def judge(N):
    res, cnt = 1, 0
    while(True):
        if(res >= N): break
        res *= 3
        cnt += 1
    if(res == N): return cnt
    else: return -1


def main():
    N = int(input())
    ans = -1
    res, cnt = 1, 0

    while(res <= N):
        if(judge(N - res) >= 0):
            ans = judge(N - res)
            break
        res *= 5
        cnt += 1

    if(ans < 1 or cnt < 1): print(-1)
    else: print(ans, cnt)


if __name__ == "__main__":
    main()
