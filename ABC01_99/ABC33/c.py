from collections import deque


def main():
    S = input()
    d = deque([])
    d.append(int(S[0]))
    for i in range(1, len(S)):
        if (i % 2):
            if (S[i] == '+'):
                d.append(int(S[i + 1]))
            else:
                cur = d[-1] * int(S[i + 1])
                d.pop()
                d.append(cur)
    ans = len(d)
    print(ans - d.count(0))


if __name__ == "__main__":
    main()
