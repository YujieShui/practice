file_name = 'learning_python.txt'

print('第一次打印时读取整个文件')
with open(file_name) as file_object:
    contents = file_object.read()
    print(contents)

print('\n第二次打印时遍历文件对象')
with open(file_name) as file_object:
    lines =file_object.readlines()

pi_string = ''
for line in lines:
    pi_string += line
print(pi_string)

print('\n第三次打印时将各行存储在一个列表中')
file_list = []
with open(file_name) as file_object:
    file_list.append(file_object.readlines())
print(file_list)