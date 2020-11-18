def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    for i in range(K, N):
        print('Yes') if(A[i] > A[i - K]) else print('No')

if __name__ == "__main__":
    main()
