#pragma once
#include "Point.h"

template<typename Dt>
class MegerSortBP
{
public:
	MegerSortBP();
	void ascendingOrder(Dt*& arr, int elements);
	void descendingOrder(Dt*& arr, int elements);

private:
	int _size;
	Dt  aux;
	Dt* ptrMain;
	Dt* ptrLeft;
	int lenLeft;
	Dt* ptrRight;
	int lenRight;
		
	void _ascending(Dt*& left, Dt*& right, int begin, int end);
	void _descending(Dt*& left, Dt*& right, int begin, int end);
	int  _copySubArray(Dt*& subArray, int begin, int end);
	
};

