# 元组的使用
foods = ('白菜','青菜','花菜')
for food in foods:
    print(food)

# foods[0] = 'aa'
# Traceback (most recent call last):
#   File "list_4.5.py", line 5, in <module>
#     foods[0] = 'aa'
# TypeError: 'tuple' object does not support item assignment

print('==========')

foods = ('青菜','花菜')
for food in foods:
    print(food)