s = input()
t = input()
s = ''.join(sorted(s))
t = ''.join(sorted(t, reverse=True))
print('Yes') if s < t else print('No')
