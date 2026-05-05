n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
cnt = 0
for x in a:
    if k < x:
        break
    k -= x
    cnt += 1
print(cnt)
