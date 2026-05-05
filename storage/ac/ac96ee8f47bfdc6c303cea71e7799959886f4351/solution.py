s = int(input())
a = s // 100
b = s // 10 % 10
c = s % 10
ans = max(a * b + c, a * b - c, a + b * c, a + b - c, a - b * c, a - b + c)
print(ans)
