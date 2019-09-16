# 循环输出 1-20
for num in range(1,21):
    print(num)

# 输出 1-20 的奇数, range() 第三个参数是步长
for num in range(1,21,2):
    print(num)

# 创建一个列表，列表中包含的是 3-30 中能被 3 整除的数字
numbers = []
for num in range(3,31):
    if(num % 3 == 0):
        numbers.append(num)
print(numbers)

# 解析列表包含 1-10 的立方
numbers = [num ** 3 for num in range(1,11)]
print(numbers)