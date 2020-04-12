weekday = ['Monday','Tuesday','Wednesday','Thursday','Friday']
day = input()
for i in range(5):
  if(weekday[i] == day):
    print(5 - i)
    exit(0)
print(0)
