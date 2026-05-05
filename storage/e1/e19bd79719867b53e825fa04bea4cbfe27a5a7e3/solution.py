n = int(input())
s = input()

answ = 0
curr = 0
for i in range(n) :
    if (s[i] == '1') :
        answ += i - curr;
        curr += 1
print(answ)
