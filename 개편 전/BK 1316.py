s = int(input())
cnt = 0
for k in range(s):
    abc = [1 for _ in range(26)]
    t = input() + ';'
    for i in range(len(t)-1):
        if t[i] != t[i + 1]:
            if abc[ord(t[i]) - 97] == 0:
                cnt += 1
                break
            else:
                abc[ord(t[i]) - 97] = 0
print(s - cnt)
