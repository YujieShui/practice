# 把字典存档到列表中
user = {}
users = []
for i in range(0,5):
    user[i] = {'NO':i,'SEX':'man'}
    users.append(user[i])

for u in users:
    print("用户编号：" + str(u['NO']))
    print("用户编号：" + u['SEX'])