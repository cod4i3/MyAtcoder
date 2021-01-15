def main():
    N = int(input())
    ans = 0
    for num in range(1, N + 1):
        res = num
        flag = False
        while(res):
            if(res % 10 == 7): flag = True
            res //= 10
        res = num
        while(res):
            if(res % 8 == 7): flag = True
            res //= 8
        if(not flag): ans += 1
    print(ans)


if __name__ == "__main__":
    main()
