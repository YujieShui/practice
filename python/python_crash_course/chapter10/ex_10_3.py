username = input('请输入您的用户名: ')

with open('guest.txt','a') as file_object:
    file_object.write(username)