
while True:

    number1 = input('Enter first number: ')
    number2 = input('Enter second number: ')

    try:
        sum = int(number1) + int(number2)
    except ValueError:
        print('Warning: Please enter a number.')
        pass
    else:
        print(str(number1) + ' + ' + str(number2) + ' = ' + str(sum))