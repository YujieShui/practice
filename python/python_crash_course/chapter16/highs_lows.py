import csv
from matplotlib import pyplot as plt
from datetime import datetime

file_name = 'sitka_weather_2014.csv'

# 读取文件头的信息,调用了 next() 获取一行中的信息
with open(file_name) as f:
    reader = csv.reader(f)
    header_row = next(reader)

    # 从文件中获取最高气温和日期
    highs = []
    dates = []
    for row in reader:
        highs.append(row[1])
        current_date = datetime.strptime(row[0],"%Y-%m-%d")
        dates.append(current_date)
    
# 使用 matplotlib 绘制图形
fig = plt.figure(dpi=128,figsize=(10,6))
plt.plot(dates,highs,c='red')

# 设置图形格式
plt.title('Daily high temperatures - 2014',fontsize=24)
plt.xlabel('',fontsize=16)
fig.autofmt_xdate() # 来绘制斜的日期标签
plt.ylabel('Temperature(F)',fontsize=16)
plt.tick_params(axis='both',which='major',labelsize=6)

plt.show()