if __name__ == "__main__":
  K = int(input()) 
  if(K % 2 == 0 or K % 5 == 0):
    print(-1)
  else:
    num = 7
    ans = 1
    while(True):
      if(num % K == 0): break
      num %= K
      num *= 10
      num += 7
      ans += 1
    print(ans)
  exit(0)
