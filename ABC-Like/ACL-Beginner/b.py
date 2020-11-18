A, B, C, D = map(int, input().split())
print('Yes') if(B >= C >= A or D >= A >= C) else print('No')