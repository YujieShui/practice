# Task2

1）列表：标志、基本操作(创建，append( )，pop( ) ,del( ), 拷贝）、列表相关方法

2）元组：标志、基本操作（创建及不可变性）

3）string字符串：定义及基本操作（+，*，读取方式）、字符串相关方法、字符串格式化问题

# 列表

> 1）列表：标志、基本操作(创建，append( )，pop( ) ,del( ), 拷贝）、列表相关方法

列表定义，下标访问，添加删除元素

```python
def main():
    # 定义
    list1 = [1, 3, 5, 7, 100]
    print(list1)
    list2 = ['hello'] * 5
    print(list2)
    # 计算列表长度(元素个数)
    print(len(list1))
    # 下标(索引)运算
    print(list1[0])
    print(list1[4])
    # print(list1[5])  # IndexError: list index out of range
    print(list1[-1])
    print(list1[-3])
    list1[2] = 300
    print(list1)
    # 添加元素
    list1.append(200)
    list1.insert(1, 400)
    list1 += [1000, 2000]
    print(list1)
    print(len(list1))
    # 删除元素
    list1.remove(3)
    if 1234 in list1:
        list1.remove(1234)
    del list1[0]
    print(list1)
    # 清空列表元素
    list1.clear()
    print(list1)


if __name__ == '__main__':
    main()
```

列表切片，复制列表

```python
def main():
    fruits = ['grape', 'apple', 'strawberry', 'waxberry']
	fruits += ['pitaya', 'pear', 'mango']
	# 循环遍历列表元素
    for fruit in fruits:
        print(fruit.title(), end=' ')
    print()
    # 列表切片
    fruits2 = fruits[1:4]
    print(fruits2)
    # fruit3 = fruits  # 没有复制列表只创建了新的引用
    # 可以通过完整切片操作来复制列表
    fruits3 = fruits[:]
    print(fruits3)
    fruits4 = fruits[-3:-1]
    print(fruits4)
    # 可以通过反向切片操作来获得倒转后的列表的拷贝
    fruits5 = fruits[::-1]
    print(fruits5)


if __name__ == '__main__':
    main()
```

#元组

> 2）元组：标志、基本操作（创建及不可变性）

元组和列表类似，但是元组中的元素不能修改。

```python
def main():
    # 定义元组
    t = ('aaa', 111, True, 'bbb')
    print(t)
    # 获取元组中的元素
    print(t[0])
    print(t[3])
    # 遍历元组中的值
    for member in t:
        print(member)
    # 重新给元组赋值
    # t[0] = '王大锤'  # TypeError
    # 变量t重新引用了新的元组原来的元组将被垃圾回收
    t = ('ccc', 222, True, 'ddd')
    print(t)
    
    # 将元组转换成列表
    person = list(t)
    print(person)
    # 列表是可以修改它的元素的
    person[0] = '李小龙'
    person[1] = 25
    print(person)
    # 将列表转换成元组
    fruits_list = ['apple', 'banana', 'orange']
    fruits_tuple = tuple(fruits_list)
    print(fruits_tuple)


if __name__ == '__main__':
    main()
```



# string 字符串

> 3）string字符串：定义及基本操作（+，*，读取方式）、字符串相关方法、字符串格式化问题

>  **字符串**（英语：**string**），是由零个或多个[字符](https://zh.wikipedia.org/wiki/字符)组成的有限序列。它是[编程语言](https://zh.wikipedia.org/wiki/编程语言)中表示[文本](https://zh.wikipedia.org/wiki/文本)的[数据类型](https://zh.wikipedia.org/wiki/資料型別)。
>
> —— [字符串- 维基百科，自由的百科全书](https://zh.wikipedia.org/zh-hans/字符串)

在 python 中比如 'abc' 是字符串，除了单引号，也可以说使用双引号、三引号表示字符串。

## 字符串基本操作

```python
# 字符基本操作

# 用 + 拼接字符串
>>> str1='123'
>>> str2='abc'
>>> str1+str2
'123abc'

# 字符串复制
>>> str='a'
>>> number=3
>>> str*number
'aaa'

# 字符串索引
>>> str="abcdefg"
>>> str[3]
'd'

# 字符串切片
str2 = 'abc123456'
str2[:] # 'abc123456' 取字符串所有内容
str2[2:] # c123456 索引从0开始的所有字符，[2,)
str2[:2] # ab 索引0到1，[0,2)
str2[2:5] # c12 [2,5)
str2[2::2] # c246 [2,) step = 2
str2[::2] # ac246 [,) step = 2

str2[-2:] # 56 负数则从后开始计数
str2[:-2] # 'abc1234'
str2[-5,-2] # 234
str2[::-1] # 654321cba 倒着取，step=1
```

## 字符串相关方法

```python
str = 'abc123456'
len(str) # 9,字符串长度
str.capitalize() # Abc123456 首字母大写
str.upper() # ABC123456 字符串大写
str.find('12') # 3 查找子串位置

str.startswith('ab') # True 判断字符串是否以指定字符开头
str.endswith('cc') # False 判断字符串是否以指定字符结尾

str.isdigit() # False 判断字符串是否由数字构成
str.isalpha())  # False 判断字符串是否由字母构成
str.isalnum())  # True 判断字符串是否由字符和字母构成
str.strip() # 去掉字符串两边空格
```

## 字符串格式化问题

```python
# 无参数
str = 'Hello {} {}'
str.format('world', '!')
'Hello world !'

# 索引参数
str = 'I {0} {1} {0} {1}'
str.format('love', 'you')
'I love you love you'

# 关键字参数
str = 'I {a} {b}'
str.format(a = 'love', b = 'you')
'I love you'
```

[python中str常用操作](https://www.cnblogs.com/mlgjb/p/7879813.html)

