#include <iostream>
#include <cmath>

using namespace std;


class Point;

class PointManager
{
public:
	double PointDistance(Point & p1, Point &p2);
};

class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void printPoint()
	{
		cout << "x = " << x << ", y = " << y << endl;
	}

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}

	friend double PointDistance(Point & p1, Point &p2);

	friend double PointManager::PointDistance(Point & p1, Point &p2); 

private:

	int x;
	int y;

};


double PointManager::PointDistance(Point & p1, Point &p2)
{
	//int dd_x = p1.getX() - p2.getX();
	int dd_x = p1.x - p2.x;
	//int dd_y = p1.getY() - p2.getY();
	int dd_y = p1.y - p2.y;

	return sqrt(dd_x*dd_x + dd_y*dd_y);
}

double PointDistance(Point & p1, Point &p2)
{
	//int dd_x = p1.getX() - p2.getX();
	int dd_x = p1.x - p2.x;
	//int dd_y = p1.getY() - p2.getY();
	int dd_y = p1.y - p2.y;

	return sqrt(dd_x*dd_x + dd_y*dd_y);
}

int main(void)
{
	Point p1(1, 2);
	Point p2(0, 0);

	cout << PointDistance(p1, p2) << endl;
 
	PointManager pm;
	cout << pm.PointDistance(p1, p2) << endl;

	return 0;
}