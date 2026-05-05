s, n, vw = input(), int(input()), "aeiouy"
d = dict()
for i in range(n):
    t = input()
    for x in vw:
        t = t.replace(x, '*')
    d[t] = d.get(t, [])
    d[t].append(i)
for x in vw:
    s = s.replace(x, '*')
ans = [0] * n
for x in d.get(s, []):
    ans[x] = 1
for i in range(n):
    print("YES" if ans[i] else "NO")
