# Task5

1. 类和对象
2. 正则表达式
3. re模块
4. http请求

# 类和对象

- 对象,将事物抽象成属性和方法.
- 面向对象编程,利用封装,继承,多态的特性构建程序
- 类,实现面向对象的方式

## 定义一个类

```Python
class Student(object):

    # __init__是一个特殊方法用于在创建对象时进行初始化操作
    # 通过这个方法我们可以为学生对象绑定name和age两个属性
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def study(self, course_name):
        print('%s正在学习%s.' % (self.name, course_name))

    # PEP 8要求标识符的名字用全小写多个单词用下划线连接
    # 但是很多程序员和公司更倾向于使用驼峰命名法(驼峰标识)
    def watch_av(self):
        if self.age < 18:
            print('%s只能观看《熊出没》.' % self.name)
        else:
            print('%s正在观看岛国爱情动作片.' % self.name)
```

1. 一个类可以分成两部分,class header 和 class body.第一行`class`关键字修饰的是 class header,紧跟在后面缩进的是 class body.
2. 构造方法,`__init__`是构造方式,用于初始化类中的变量
3. 属性,`name`和`age`是 Student 类的属性
4. `study()` 和 `watch_av()` 是 Student 类的成员方法

## 使用一个类

```Python
def main():
    # 调用构造方法,初始化一个类
    stu1 = Student('骆昊', 38)
    # 调用类中的方法
    stu1.study('Python程序设计')
    # 给对象发watch_av消息
    stu1.watch_av()

    stu2 = Student('王大锤', 15)
    stu2.study('思想品德')
    stu2.watch_av()


if __name__ == '__main__':
    main()
```

# 正则表达式

在编写处理字符串的程序或网页时，经常会有查找符合某些复杂规则的字符串的需要，正则表达式就是用于描述这些规则的工具，换句话说正则表达式是一种工具，它定义了字符串的匹配模式（如何检查一个字符串是否有跟某种模式匹配的部分或者从一个字符串中将与模式匹配的部分提取出来或者替换掉）。如果你在Windows操作系统中使用过文件查找并且在指定文件名时使用过通配符（\*和?），那么正则表达式也是与之类似的用来进行文本匹配的工具，只不过比起通配符正则表达式更强大，它能更精确地描述你的需求（当然你付出的代价是书写一个正则表达式比打出一个通配符要复杂得多，要知道任何给你带来好处的东西都是有代价的，就如同学习一门编程语言一样），比如你可以编写一个正则表达式，用来查找所有以0开头，后面跟着2-3个数字，然后是一个连字号“-”，最后是7或8位数字的字符串（像028-12345678或0813-7654321），这不就是国内的座机号码吗。最初计算机是为了做数学运算而诞生的，处理的信息基本上都是数值，而今天我们在日常工作中处理的信息基本上都是文本数据，我们希望计算机能够识别和处理符合某些模式的文本，正则表达式就显得非常重要了。今天几乎所有的编程语言都提供了对正则表达式操作的支持，Python通过标准库中的re模块来支持正则表达式操作。

我们可以考虑下面一个问题：我们从某个地方（可能是一个文本文件，也可能是网络上的一则新闻）获得了一个字符串，希望在字符串中找出手机号和座机号。当然我们可以设定手机号是11位的数字（注意并不是随机的11位数字，因为你没有见过“25012345678”这样的手机号吧）而座机号跟上一段中描述的模式相同，如果不使用正则表达式要完成这个任务就会很麻烦。

关于正则表达式的相关知识，大家可以阅读一篇非常有名的博客叫[《正则表达式30分钟入门教程》](https://deerchao.net/tutorials/regex/regex.htm)，读完这篇文章后你就可以看懂下面的表格，这是我们对正则表达式中的一些基本符号进行的扼要总结。

| 符号               | 解释                                      | 示例             | 说明                                               |
| ------------------ | ----------------------------------------- | ---------------- | -------------------------------------------------- |
| .                  | 匹配任意字符                              | b.t              | 可以匹配bat / but / b#t / b1t等                    |
| \\w                | 匹配字母/数字/下划线                      | b\\wt            | 可以匹配bat / b1t / b_t等<br>但不能匹配b#t         |
| \\s                | 匹配空白字符（包括\r、\n、\t等）          | love\\syou       | 可以匹配love you                                   |
| \\d                | 匹配数字                                  | \\d\\d           | 可以匹配01 / 23 / 99等                             |
| \\b                | 匹配单词的边界                            | \\bThe\\b        |                                                    |
| ^                  | 匹配字符串的开始                          | ^The             | 可以匹配The开头的字符串                            |
| $                  | 匹配字符串的结束                          | .exe$            | 可以匹配.exe结尾的字符串                           |
| \\W                 | 匹配非字母/数字/下划线                    | b\\Wt            | 可以匹配b#t / b@t等<br>但不能匹配but / b1t / b_t等 |
| \\S                 | 匹配非空白字符                            | love\\Syou       | 可以匹配love#you等<br>但不能匹配love you           |
| \\D                 | 匹配非数字                                | \\d\\D           | 可以匹配9a / 3# / 0F等                             |
| \\B                 | 匹配非单词边界                            | \\Bio\\B         |                                                    |
| []                 | 匹配来自字符集的任意单一字符              | [aeiou]          | 可以匹配任一元音字母字符                           |
| [^]                | 匹配不在字符集中的任意单一字符            | [^aeiou]         | 可以匹配任一非元音字母字符                         |
| *                  | 匹配0次或多次                             | \\w*             |                                                    |
| +                  | 匹配1次或多次                             | \\w+             |                                                    |
| ?                  | 匹配0次或1次                              | \\w?             |                                                    |
| {N}                | 匹配N次                                   | \\w{3}            |                                                    |
| {M,}               | 匹配至少M次                               | \\w{3,}           |                                                    |
| {M,N}              | 匹配至少M次至多N次                        | \\w{3,6}          |                                                    |
| \|                 | 分支                                      | foo\|bar         | 可以匹配foo或者bar                                 |
| (?#)               | 注释                                      |                  |                                                    |
| (exp)              | 匹配exp并捕获到自动命名的组中             |                  |                                                    |
| (?&nbsp;&lt;name&gt;exp) | 匹配exp并捕获到名为name的组中             |                  |                                                    |
| (?:exp)            | 匹配exp但是不捕获匹配的文本               |                  |                                                    |
| (?=exp)            | 匹配exp前面的位置                         | \\b\\w+(?=ing)     | 可以匹配I'm dancing中的danc                        |
| (?<=exp)           | 匹配exp后面的位置                         | (?<=\\bdanc)\\w+\\b | 可以匹配I love dancing and reading中的第一个ing    |
| (?!exp)            | 匹配后面不是exp的位置                     |                  |                                                    |
| (?<!exp)           | 匹配前面不是exp的位置                     |                  |                                                    |
| *?                 | 重复任意次，但尽可能少重复 | a.\*b<br>a.\*?b | 将正则表达式应用于aabab，前者会匹配整个字符串aabab，后者会匹配aab和ab两个字符串 |
| +?                 | 重复1次或多次，但尽可能少重复 |                  |                                                    |
| ??                 | 重复0次或1次，但尽可能少重复 |                  |                                                    |
| {M,N}?             | 重复M到N次，但尽可能少重复 |                  |                                                    |
| {M,}?              | 重复M次以上，但尽可能少重复 |                  |                                                    |

> **说明：** 如果需要匹配的字符是正则表达式中的特殊字符，那么可以使用\\进行转义处理，例如想匹配小数点可以写成\\.就可以了，因为直接写.会匹配任意字符；同理，想匹配圆括号必须写成\\(和\\)，否则圆括号被视为正则表达式中的分组。

## re 模块,Python对正则表达式的支持

Python提供了re模块来支持正则表达式相关操作，下面是re模块中的核心函数。

| 函数                                         | 说明                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| compile(pattern, flags=0)                    | 编译正则表达式返回正则表达式对象                             |
| match(pattern, string, flags=0)              | 用正则表达式匹配字符串 成功返回匹配对象 否则返回None         |
| search(pattern, string, flags=0)             | 搜索字符串中第一次出现正则表达式的模式 成功返回匹配对象 否则返回None |
| split(pattern, string, maxsplit=0, flags=0)  | 用正则表达式指定的模式分隔符拆分字符串 返回列表              |
| sub(pattern, repl, string, count=0, flags=0) | 用指定的字符串替换原字符串中与正则表达式匹配的模式 可以用count指定替换的次数 |
| fullmatch(pattern, string, flags=0)          | match函数的完全匹配（从字符串开头到结尾）版本                |
| findall(pattern, string, flags=0)            | 查找字符串所有与正则表达式匹配的模式 返回字符串的列表        |
| finditer(pattern, string, flags=0)           | 查找字符串所有与正则表达式匹配的模式 返回一个迭代器          |
| purge()                                      | 清除隐式编译的正则表达式的缓存                               |
| re.I / re.IGNORECASE                         | 忽略大小写匹配标记                                           |
| re.M / re.MULTILINE                          | 多行匹配标记                                                 |

> **说明：** 上面提到的re模块中的这些函数，实际开发中也可以用正则表达式对象的方法替代对这些函数的使用，如果一个正则表达式需要重复的使用，那么先通过compile函数编译正则表达式并创建出正则表达式对象无疑是更为明智的选择。

# http 请求

## 单线程服务器

```Python
from socket import socket, SOCK_STREAM, AF_INET
from datetime import datetime

def main():
    # 1.创建套接字对象并指定使用哪种传输服务
    # family=AF_INET - IPv4地址
    # family=AF_INET6 - IPv6地址
    # type=SOCK_STREAM - TCP套接字
    # type=SOCK_DGRAM - UDP套接字
    # type=SOCK_RAW - 原始套接字
    server = socket(family=AF_INET, type=SOCK_STREAM)
    # 2.绑定IP地址和端口(端口用于区分不同的服务)
    # 同一时间在同一个端口上只能绑定一个服务否则报错
    server.bind(('192.168.1.2', 6789))
    # 3.开启监听 - 监听客户端连接到服务器
    # 参数512可以理解为连接队列的大小
    server.listen(512)
    print('服务器启动开始监听...')
    while True:
        # 4.通过循环接收客户端的连接并作出相应的处理(提供服务)
        # accept方法是一个阻塞方法如果没有客户端连接到服务器代码不会向下执行
        # accept方法返回一个元组其中的第一个元素是客户端对象
        # 第二个元素是连接到服务器的客户端的地址(由IP和端口两部分构成)
        client, addr = server.accept()
        print(str(addr) + '连接到了服务器.')
        # 5.发送数据
        client.send(str(datetime.now()).encode('utf-8'))
        # 6.断开连接
        client.close()

if __name__ == '__main__':
    main()
```

## 单线程客户端

```Python
from socket import socket

def main():
    # 1.创建套接字对象默认使用IPv4和TCP协议
    client = socket()
    # 2.连接到服务器(需要指定IP地址和端口)
    client.connect(('192.168.1.2', 6789))
    # 3.从服务器接收数据
    print(client.recv(1024).decode('utf-8'))
    client.close()

if __name__ == '__main__':
    main()
```

## 多线程的服务器端

需要注意的是，上面的服务器并没有使用多线程或者异步I/O的处理方式，这也就意味着当服务器与一个客户端处于通信状态时，其他的客户端只能排队等待。很显然，这样的服务器并不能满足我们的需求，我们需要的服务器是能够同时接纳和处理多个用户请求的。下面我们来设计一个使用多线程技术处理多个用户请求的服务器，该服务器会向连接到服务器的客户端发送一张图片。

```Python
from socket import socket, SOCK_STREAM, AF_INET
from base64 import b64encode
from json import dumps
from threading import Thread


def main():
    
    # 自定义线程类
    class FileTransferHandler(Thread):

        def __init__(self, cclient):
            super().__init__()
            self.cclient = cclient

        def run(self):
            my_dict = {}
            my_dict['filename'] = 'guido.jpg'
            # JSON是纯文本不能携带二进制数据
            # 所以图片的二进制数据要处理成base64编码
            my_dict['filedata'] = data
            # 通过dumps函数将字典处理成JSON字符串
            json_str = dumps(my_dict)
            # 发送JSON字符串
            self.cclient.send(json_str.encode('utf-8'))
            self.cclient.close()

    # 1.创建套接字对象并指定使用哪种传输服务
    server = socket()
    # 2.绑定IP地址和端口(区分不同的服务)
    server.bind(('192.168.1.2', 5566))
    # 3.开启监听 - 监听客户端连接到服务器
    server.listen(512)
    print('服务器启动开始监听...')
    with open('guido.jpg', 'rb') as f:
        # 将二进制数据处理成base64再解码成字符串
        data = b64encode(f.read()).decode('utf-8')
    while True:
        client, addr = server.accept()
        # 启动一个线程来处理客户端的请求
        FileTransferHandler(client).start()


if __name__ == '__main__':
    main()
```

## 多线程的客户端

```Python
from socket import socket
from json import loads
from base64 import b64decode


def main():
    client = socket()
    client.connect(('192.168.1.2', 5566))
    # 定义一个保存二进制数据的对象
    in_data = bytes()
    # 由于不知道服务器发送的数据有多大每次接收1024字节
    data = client.recv(1024)
    while data:
        # 将收到的数据拼接起来
        in_data += data
        data = client.recv(1024)
    # 将收到的二进制数据解码成JSON字符串并转换成字典
    # loads函数的作用就是将JSON字符串转成字典对象
    my_dict = loads(in_data.decode('utf-8'))
    filename = my_dict['filename']
    filedata = my_dict['filedata'].encode('utf-8')
    with open('/Users/Hao/' + filename, 'wb') as f:
        # 将base64格式的数据解码成二进制数据并写入文件
        f.write(b64decode(filedata))
    print('图片已保存.')


if __name__ == '__main__':
    main()
```

在这个案例中，我们使用了JSON作为数据传输的格式（通过JSON格式对传输的数据进行了序列化和反序列化的操作），但是JSON并不能携带二进制数据，因此对图片的二进制数据进行了Base64编码的处理。Base64是一种用64个字符表示所有二进制数据的编码方式，通过将二进制数据每6位一组的方式重新组织，刚好可以使用0~9的数字、大小写字母以及“+”和“/”总共64个字符表示从`000000`到`111111`的64种状态。[维基百科](https://zh.wikipedia.org/wiki/Base64)上有关于Base64编码的详细讲解，不熟悉Base64的读者可以自行阅读。