N = input()
print('Yes') if(int(N) % sum([int(c) for c in list(N)]) == 0) else print('No')
