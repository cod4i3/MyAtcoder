def main():
    s = input()
    K = int(input())
    N = len(s)
    l = []
    for i in range(N):
        for j in range(i + 1, i + 6):
          l.append(s[i:j])
    ans = list(set(l))
    ans.sort()
    print(ans[K -1])

if __name__ == "__main__":
    main()
