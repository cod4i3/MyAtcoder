
def pow_k(x, n):
    """
    O(log n)
    """
    if n == 0:
        return 1

    K = 1
    while n > 1:
        if n % 2 != 0:
            K *= x
        x *= x
        n //= 2

    return K * x


def main():
    from math import ceil
    N = int(input())
    A = list(map(int, input().split()))

    if(N == 0):
        if(A[0] == 1):
            print(1)
        else:
            print(-1)
        exit(0)
    if(A[0] != 0 or A[N] == 0):
        print(-1)
        exit(0)
    # curは作り出せる最大ノード数
    if(N == 1):
        print(A[1] + 1)
        exit(0)
    cur = 0
    S = [0] * (N + 1)
    for i in range(N, 0, -1):
        cur += A[i]
        S[i - 1] = cur
    # print(S)

    ans, cur = 0, 2
    node = [0] * (N + 1)
    a = [0] * (N + 1)
    node[0] = 2
    for i in range(1, N + 1):
        if(A[i] > cur):
            print(-1)
            exit(0)
        if(A[i] > pow(2, i)):
            print(-1)
            exit(0)
        cur = 2 * (cur - A[i])
        node[i] = cur

        if(node[i] > S[i]): node[i] = S[i]
        a[i] = node[i - 1] + cur
        # print("i={}, cur={}".format(i, cur))
    # print(node)
    # print(a)
    # 最初の頂点
    print(sum(node) + 1)
    '''
  cur = 0
  for i in range(N, 0, -1):
      cur += A[i]
      if(cur >= 2**(i - 1)): cur = 2**(i - 1)
      # if(cur >= 2 * A[i - 1]): cur = 2 * A[i - 1]
      ans += cur
      print(cur, ans)
  print(ans)

  '''


if __name__ == "__main__":
    main()
