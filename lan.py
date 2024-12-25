'''
y为一天的题目
x为天数
a,b为加减两数
c用来判断加减号
z用来表示题号
'''
from random import randint

x = int(input('请输入天数：'))
y = 1
z = 0

for i in range(1,x+1):
    print('第%s天'%i)
    while y < 14:
        a = randint(10,99)
        b = randint(10,99)
        c = randint(0,1)
        z += 1
        if c == 0:
            print('%s.%s + %s = '%(z,a,b))
        else:
            if a > b:
                print('%s.%s - %s = '%(z,a,b))
            else:
                print('%s.%s - %s = '%(z,b,a))
        y += 1
    y = 1
    z = 0
    print()
    print()
