s = input()
alpha = [chr(ord('a') + i) for i in range(26)]
for letter in s:
    if(alpha.count(letter)): alpha.remove(letter)
print(alpha[0]) if alpha else print('None')
