active = True;
while active:
    age = input('请输入您的年龄: ')
    age = int(age)
    if age < 3:
        print('票价免费')
    elif age >= 3 and age <= 12:
        print('10 美元每位')
    else:
        print('15 美元每位')