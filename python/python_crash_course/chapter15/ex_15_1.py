import matplotlib.pyplot as plt

# 显示前 5 个整数的立方值
# input_value = [1,2,3,4,5]

input_value = []
# 显示前 5000 个整数的立方值
for v in range(1,5001):
    input_value.append(v)

squares = []
for v in input_value:
    squares.append(v**3)

plt.plot(input_value,squares,linewidth=5)

plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Square of value", fontsize=14)

plt.tick_params(axis='both',labelsize=14)

plt.show()