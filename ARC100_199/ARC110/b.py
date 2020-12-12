N = int(input())
T = input()
if(N == 1):
    if(T == '1'):
        print(2 * 10 ** 10)
    else:
        print(10 ** 10)
    exit(0)
if(N == 2):
    if(T == '01'):
        print(10 ** 10 - 1)
    elif(T == '00'):
        print(0)
    else:
        print(10 ** 10)
    exit(0)
if(N == 3):
    if(T.count('00')):
        print(0)
        exit(0)
    if(T == '110'):
        print(10 ** 10)
        exit(0)
    if(T == '101'):
        print(10 ** 10 - 1)
        exit(0)
    if(T == '011'):
        print(10**10 - 1)
        exit(0)
if(T.count('111')):
    print(0)
    exit(0)

S = ""
cnt = 0
while(len(S) < N):
    S += '110'
    cnt += 1

#print(S, T, S.count(T))
if(S.count(T) == 0):
    S += '110'
    cnt += 1
if(S.count(T) == 0):
    print(0)
    exit(0)

print(10 ** 10 - cnt + 1)
