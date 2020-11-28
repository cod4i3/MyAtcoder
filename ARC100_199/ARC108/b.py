def main():
  N = int(input())
  s = input()
  t = ""
  ans = 0
  for i in range(N):
      t += s[i]
      if(len(t) >= 3):
        if(t == "fox"):
          t = ""
          ans += 3
          continue
        if(t[-3:] == "fox"):
          t = t[:-3]
          ans += 3
  print(N - ans)

if __name__ == "__main__":
  main()