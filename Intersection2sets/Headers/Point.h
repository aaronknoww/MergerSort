#pragma once
class Point
{
public:

	Point();
	Point(int x, int y);
	int getX();
	int getY();
	bool operator<(const Point & obj);
	bool operator>(const Point& obj);
	bool operator==(const Point& obj);
	bool operator<=(const Point& obj);
	bool isEqual(const Point& obj);

private:
	int x;
	int y;

};

