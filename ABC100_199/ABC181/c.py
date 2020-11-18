def Yes():
  print('Yes')
  exit(0)

def No():
  print('No')
  exit(0)

def main():
  N = int(input())
  p = [list(map(int, input().split())) for _ in range(N)]

  for i in range(N - 2):
      for j in range(i + 1, N - 1):
          for k in range(j + 1, N):
            x1, y1, x2, y2, x3, y3 = p[i][0], p[i][1], p[j][0], p[j][1], p[k][0], p[k][1]
            v1 = [x2 - x1, y2 - y1]
            v2 = [x3 - x1, y3 - y1]
            if(v1[0] == 0):
              if(v2[0] == 0): Yes()
              else: continue
            if(v2[0] == 0):
              if(v1[0] == 0): Yes()
              else: continue
            if(v1[1] == 0):
              if(v2[1] == 0): Yes()
              else: continue
            if(v2[1] == 0):
              if(v1[1] == 0): Yes()
              else: continue
            if(v2[0]/v1[0] == v2[1]/v1[1]): Yes()
  No()

if __name__ == "__main__":
  main()
