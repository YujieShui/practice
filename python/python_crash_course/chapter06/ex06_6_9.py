# 存储朋友的名字，和这个朋友喜欢的地方
favorite_places = {}
places_0 = ['a','b','c']
places_1 = ['d','e','f']
places_2 = ['g','h','i']

favorite_places['Mike'] = places_0;
favorite_places['Tom'] = places_1;
favorite_places['Lucy'] = places_2;

for k,v in favorite_places.items():
    print('\n' + k + " 'favorite place is: ")
    for place in v:
        print(place + ",")