a ,b,c = 300,60,10
time = int(input())
time , a = (time - a*(time//a)),time//a
time , b = (time - b*(time//b)),time//b
time , c = (time - c*(time//c)),time//c
if time :
    print(-1)
else:
    print(a,b,c)