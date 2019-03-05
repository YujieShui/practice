file_name = 'pi_digits.txt'

# 读取一个文件
with open(file_name) as file_object:
    contents = file_object.read()
    print(contents)

# 逐行读取文件内容
with open(file_name) as file_object:
    for line in file_object:
        print(line.rstrip())