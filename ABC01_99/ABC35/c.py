#imos法
#他にはセグメント木、BITなどがあるらしい
def main():
    N, Q = map(int, input().split())
    num = [0] * (N + 1)
    ans = ['0'] * (N + 1)
    for i in range(Q):
        l, r = map(int, input().split())
        num[l - 1] ^= 1
        num[r] ^= 1

    cur = 0
    for i in range(N):
        cur += num[i]
        if(cur % 2): ans[i] = '1'
        else: ans[i] = '0'
    print(''.join(ans)[:N])


if __name__ == "__main__":
    main()
