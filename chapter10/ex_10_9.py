cats_file = 'cats.txt'
dogs_file = 'dogs.txt'

try:
    with open(cats_file) as file_object:
        contents = file_object.read()
        print(contents)
    
    with open(dogs_file) as file_object:
        contents = file_object.read()
        print(contents)
except FileNotFoundError:
    pass