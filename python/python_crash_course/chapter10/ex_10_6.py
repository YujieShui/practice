number1 = input('Enter first number: ')
number2 = input('Enter second number: ')

try:
    sum = int(number1) + int(number2)
except ValueError:
    print('Please enter a number.')
else:
    print(str(number1) + ' + ' + str(number2) + ' = ' + str(sum))