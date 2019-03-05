file_name = 'programming.txt'

# open 可以添加参数
# 默认 r - 只读
# w - 写入
# a - 附加模式
# r+ - 读取和写入
with open(file_name,'w') as file_object:
    file_object.write('I love programming.\n')
    file_object.write('I love creating a new game.\n')