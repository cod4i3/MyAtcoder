def main():
  S = input()
  from collections import Counter
  C = Counter(S)
  for i in range(0, 1001, 8):
    st = str(i).zfill(min(len(S), 3))
    flag = True
    for e in st:
      if(st.count(e) > C[e]):
        flag = False
    if(flag):
      print('Yes')
      exit(0)
  print('No')

if __name__ == "__main__":
  main()
