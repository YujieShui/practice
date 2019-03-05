# 读取文件，替换 python 字符串
file_name = 'learning_python.txt'

with open(file_name) as file_object:
    contents = file_object.read()
    print(contents.replace('python','java'))
