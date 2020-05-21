from math import cos
from math import sin
from math import sqrt
from math import pi
from math import radians
A, B, H, M = map(int, input().split())
rad_long = (-360 * (M / 60) + 90)
rad_long = radians(rad_long)
rad_short = -30 * H - (M / 12) * 6 + 90
rad_short = radians(rad_short)
#print(rad_long, rad_short)

short_plot = [A * cos(rad_short), A * sin(rad_short)]
long_plot = [B * cos(rad_long), B * sin(rad_long)]
#print(short_plot)
#print(long_plot)

x = (short_plot[0] - long_plot[0])
y = (short_plot[1] - long_plot[1])
#print(x, y)

print(sqrt(x ** 2 + y**2))
