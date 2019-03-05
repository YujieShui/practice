file_name = 'guest_book.txt'

while True:
    username = input('输入用户名: ')
    print('欢迎光临：' + username)
    with open(file_name,'a') as file_object:
        file_object.write(username + '\n')
