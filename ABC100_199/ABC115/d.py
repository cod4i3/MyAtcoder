def main():
    N, X = map(int, input().split())
    L = [1] * 60
    P = [1] * 60
    cnt = 0
    for i in range(1, 55):
        # バーガーとパティの長さ
        L[i] = 3 + L[i - 1] * 2
        P[i] = P[i - 1] * 2 + 1

    
    


if __name__ == '__main__':
    main()
    exit(0)
