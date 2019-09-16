from die import Die
import pygal

die = Die()

# 制作一些数据，模拟抛掷色子 1000 次
results = []
for roll in range(1000):
    result = die.roll()
    results.append(result)

# 分析结果，统计 1~6 每个数字出现的次数
frequences = []

for value in range(1,die.num_sides):
    frequeny = results.count(value)
    frequences.append(frequeny)

print(frequences)

# 利用 pygal 实现数据可视化
hist = pygal.Bar()

hist.title = "Result of rolling one D6 1000 times"
hist.x_labels = [1,2,3,4,5,6]
hist.x_title = "Result"
hist.y_title = "Frequent of Result"

hist.add('D6',frequences)
hist.render_to_file('die_visual.svg')