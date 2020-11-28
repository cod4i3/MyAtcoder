def main():
  N, M = map(int, input().split())
  ball = [1] * N
  ans = [0] * N
  ans[0] = 1
  for i in range(M):
      x, y = map(int, input().split())
      x, y = x - 1, y - 1
      ball[x] -= 1
      ball[y] += 1
      if(ans[x] == 1):
        ans[y] = 1
      if(ball[x] == 0): ans[x] = 0
  print(sum(ans))

if __name__ == "__main__":
  main()