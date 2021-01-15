def main():  
    N = int(input())
    A = [float(input()) for i in range(N)]
    A = [int(round(A[i] * 10 ** 9)) for i in range(N)]

    two_five = [[0]* 20 for _ in range(50)] 
    num2, num5 = [0] * N, [0] * N
    for i in range(N):
        res = A[i]
        two, five = 0, 0
        while(res % 2 == 0):
            res //= 2
            two += 1
        while(res % 5 == 0):
            res //= 5
            five += 1
        two_five[two][five] += 1
        num2[i], num5[i] = two, five

    ans = 0
    for i in range(N):
        for j in range(18 - num2[i], 50):
          for k in range(18 - num5[i], 20):
            ans += two_five[j][k]
            if(j == num2[i] and k == num5[i]): ans -= 1
        two_five[num2[i]][num5[i]] -= 1
    print(ans)

if __name__ == "__main__":
  main()