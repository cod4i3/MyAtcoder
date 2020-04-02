def lose():
    print('You will lose')


S = input()
T = input()
list = ['a', 't', 'c', 'o', 'd', 'e', 'r']
for i in range(len(S)):
    if (S[i] == T[i] == '@'):
        continue
    if (S[i] == '@' and not list.count(T[i])):
        lose()
        exit(0)
    if (T[i] == '@' and not list.count(S[i])):
        lose()
        exit(0)
    if (S[i] != '@' and T[i] != '@' and S[i] != T[i]):
        lose()
        exit(0)

print('You can win')
