from math import ceil

n, r, p, s = map(int, input().split())
s *= 100
p *= 100

for i in range(n):
    s = ceil(s * (1 + r / 100))
    s -= p
    if s <= 0:
        break
        
if s <= 0:
    print("HeWonThisLife")
else:
    print("GGWP")
