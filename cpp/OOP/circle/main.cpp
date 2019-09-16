#include "Circle.h"
#include <iostream>

int main(void)
{
	Circle c1;

	c1.setR(10.0);
    
	std::cout << c1.getGrius() << std::endl;
	std::cout << c1.getArea() << std::endl;
	
	return 0;
}