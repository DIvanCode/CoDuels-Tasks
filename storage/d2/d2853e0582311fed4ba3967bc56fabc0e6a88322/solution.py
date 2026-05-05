t = int(input())
for _ in range(t):
    presents = list(map(int, input().split()))
    presents.sort(reverse=True)
    print(presents[0] + presents[1])
