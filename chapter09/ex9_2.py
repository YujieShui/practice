class Restaurant():
    
    def __init__(self,restaurant_name,cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
    
    def desctibe_restaurant(self):
        print('餐馆名为:' + self.restaurant_name + ',菜名为：' + self.cuisine_type)

    def open_restaurant(self):
        print('餐厅正在营业')

restaurant1 = Restaurant('石浦饭店','鱼香肉丝')
restaurant2 = Restaurant('石浦饭店','鱼香肉丝')
restaurant3 = Restaurant('石浦饭店','鱼香肉丝')

restaurant1.desctibe_restaurant();
restaurant2.desctibe_restaurant();
restaurant3.desctibe_restaurant();