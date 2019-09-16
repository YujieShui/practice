print('输入 quit 停止加入配料')
active = True

while active:
    food = input('请输入披萨配料: ')
    if food == 'quit':
        active = False
    else:
        print('已加入配料' + food)