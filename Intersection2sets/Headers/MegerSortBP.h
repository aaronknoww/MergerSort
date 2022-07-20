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
	int _elment;
	Point aux;
	Point* ptrA;
	Point* ptrSub;
	void exchange(Point a, Point b);
	void _ascending(int size, int begin, int end, int total);//TODO: REVISAR LOS ATRIBUTOS QUE RECIBE ESTA FUNCION.
	
	
};

