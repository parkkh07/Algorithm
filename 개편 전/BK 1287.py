a = input()
symbol = ['+','-','*','/']
if'/0'in a or a[0] in symbol :
    print('ROCK')
    exit()

for i in range(len(a)-1):
    if a[i] in symbol and a[i+1] in symbol:
        print('ROCK')
        exit()
    if a[i] == '(' and a[i+1] in symbol:
        print('ROCK')
        exit()
    if a[i] == '(' and a[i+1] == ')':
        print('ROCK')
        exit()
    if a[i] == ')' and a[i+1] not in symbol:
        print('ROCK')
        exit()
if a.count('(') != a.count(')'):
    print('ROCK')
    exit()
a = a.replace('/','//')
print(int(eval(a)))