#pragma once
#include "Point.h"
class MegerSortBP
{
public:
	MegerSortBP();
	void ascendingOrder(Point*& arr, int elements);
	void descendingOrder(Point*& arr, int elements);

private:
	int _size;
	Point aux;
	Point* ptrA;
	Point* ptrSub;
	void exchange(Point a, Point b);
	void _ascending(int total, int begin, int end);
	void _descending(int total, int begin, int end);
	
};

