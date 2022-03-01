text = list(' '.join(input()).split(' '))

a = text.count('1') // 2 
b = text.count('0') // 2
c1 , c2 = 0, 0
print(a,b)
for i in range(len(text)):
    if text[i] == '1' :
        text[i] = ''
        c1 += 1
        if c1 == a:break

for i in range(text.count('')):
    text.remove('')


for i in range(len(text)-1,-1,-1):
    if text[i] == '0':
        text[i] = ''
        c2 += 1
        if c2 == b:break



for i in text:
    print(i,end='')