#include "../Headers/Pch.h"
#include "../Headers/Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX()
{
	return this->x;
}

int Point::getY()
{
	return this->y;
}

bool Point::operator<(const Point& obj)
{
	
	if(this->x < obj.x)
		return true;
	return false;
}

bool Point::operator>(const Point& obj)
{
	if(this->x > obj.x) 
		return true;
	return false;
}

bool Point::operator==(const Point& obj)
{
	if(this->x == obj.x)
		return true;
	return false;
}

bool Point::operator<=(const Point& obj)
{
	if (this->x <= obj.x)
		return true;
	else
		return false;
}

bool Point::isEqual(const Point& obj)
{
	if (this->x == obj.x && this->y == obj.y)
		return true;
	else
		return false;
}
