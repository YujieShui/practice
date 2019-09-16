# 输出一个嘉宾列表
name_list = ['Tom','Bob','Alice']
print(name_list)
print('=======================')

# 输出无法赴约的嘉宾名字并替换名单
print(name_list[0] + ' 无法赴约')
name_list[0] = 'John'
print(name_list)

# 用 insert() 和 append() 添加新的嘉宾
print('有更大的桌子，可以邀请更多的嘉宾')
name_list.insert(0,'Mike')
name_list.insert(1,'Lucy')
name_list.append('Lili')
print(name_list)

# 最后只能邀请两个人，练习 pop()
name_list.pop(5);
name_list.pop(4);
name_list.pop(3);
name_list.pop(2);
print('嘉宾名单最后剩余：')
print(name_list)
del(name_list[1])
del(name_list[0])
print(name_list)