A, B = map(int, input().split())
ans = 0
if (A < B): A, B = B, A
ans += (A - B) // 10
B += ans * 10
if (A < B): A, B = B, A
if (A == B): print(ans); exit(0)
B += (A - B) // 10
ans += min(1 + (A - B) % 5 + (A - B), 1 + 10 - (A - B), A - B, 1 + abs(5 - (A - B)))
print(ans)
