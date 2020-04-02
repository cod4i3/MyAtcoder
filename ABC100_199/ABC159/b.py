S = input()
N = len(S)
if (S == S[::-1] and S[: (N - 1) // 2:-1] == S[:(N - 1) // 2] and S[N:(N + 3) // 2 - 2:-1] == S[(N + 3) // 2 - 1:]):
    #print(S[::-1], S[: (N - 1) // 2:-1], S[N:(N + 3) // 2 - 2:-1])
    #print(S[::-1], S[:(N - 1) // 2], S[(N + 3) // 2 - 1:])
    print('Yes')
else: print('No')
