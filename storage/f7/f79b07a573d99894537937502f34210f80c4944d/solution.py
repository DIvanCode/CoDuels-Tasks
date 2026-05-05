n, m = map(int, input().split())
pow2 = 1
for i in range(n):
    pow2 *= 2
    if (pow2 - 1) > m:
        print("No")
        exit()
pow2 -= 1
if m % pow2 == 0:
    print("Yes")
    print(m // pow2)
else:
    print("No")
