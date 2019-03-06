from random import randint

class Die():
    """筛子类"""

    def __init__(self,num_sides=6):
        """筛子有 6 个面"""
        self.num_sides = num_sides
    
    def roll(self):
        return randint(1,self.num_sides)