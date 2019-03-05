file_name = 'pi_million_digits.txt'

with open(file_name) as file_object:
    lines = file_object.readlines()

pi_string = ''
for line in lines:
    pi_string += line.strip()

print(pi_string)
print(len(pi_string))

birthday = input('输入你的生日，以 mmddyy 格式:')

if birthday in pi_string:
    print('你的生日在圆周率中')
else:
    print('你的生日不在圆周率中')