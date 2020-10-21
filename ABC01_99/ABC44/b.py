w = input()
d = {}
for i in range(len(w)):
  if(w[i] not in d): d[w[i]] = 1
  else: d[w[i]] += 1
for i in range(len(w)):
  if(d[w[i]] % 2):
    print("No")
    exit(0)
print("Yes")