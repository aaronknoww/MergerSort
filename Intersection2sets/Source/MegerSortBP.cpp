#include "../Headers/Pch.h"
#include "../Headers/MegerSortBP.h"

using namespace std;
MegerSortBP::MegerSortBP()
{
	ptrA = nullptr;
	ptrSub = nullptr; //To create sub array.
	_size = 0;
	
}
void MegerSortBP::ascendingOrder(Point*& arr, int elements)
{
	//arr ------> Array to sort.
	//elements --> Number of elements in the array.
	
	if (elements < 1)
		throw "Out of Range";

	if (elements == 1)
		return;

	ptrA = arr;
	_size = 2;
	int total = 0;
	do
	{		
		for (size_t i = 0; i <= elements / _size; i++)
		{
			total = (_size * (i + 1) <= elements) ? _size : _size - elements;
			_ascending(total, i * _size, i * _size + _size -1);


		}
		_size += _size;

	} while (_size <= elements);


}

void MegerSortBP::descendingOrder(Point*& arr, int elements)
{
	if (elements < 1)
		throw "Out of Range";

	if (elements == 1)
		return;

	ptrA = arr;
	_size = 2;
	int total = 0;
	do
	{
		for (size_t i = 0; i <= elements / _size; i++)
		{
			total = (_size * (i + 1) <= elements) ? _size : _size - elements;
			_ascending(total, i * _size, i * _size + _size - 1);


		}
		_size += _size;

	} while (_size <= elements);
}

void MegerSortBP::exchange(Point a, Point b)
{

	aux = a;
	a = b;
	b = aux;
}

void MegerSortBP::_ascending(int total, int begin, int end)
{
	// begin--> To know in which index of the main array we want to start copying.
	// end----> To know in which index of the main array we want to end copying.
	// total--> Number of elements to be copied. 
		
	if (total < 2)
		return;

	ptrSub = new Point[total];
	for (size_t i = 0; i < total; i++)
			ptrSub[i] = ptrA[i + begin];
	
	if (total == 2)
	{
		if (ptrSub[0] <= ptrSub[1])
			return;
		else
		{
			ptrA[begin] = ptrSub[1];
			ptrA[begin + 1] = ptrSub[0];
			return;
		}

	}
	
	int start = 0;
	int med = (total & 1) ? ((total / 2) + 1) : total / 2;
	const int half = med;
		
	for (size_t i = 0; i <total; i++)
	{
		if (start<half && med<=end)
		{
			if (ptrSub[start] <= ptrSub[med])
			{
				ptrA[begin + i] = ptrSub[start];		
				start++;
			}
			else
			{
				ptrA[begin + i] = ptrSub[med];
				med++;
			}
		}
		else
		{
			if (start < half)
			{
				ptrA[begin+i] = ptrSub[start];
				start++;
			}
			else
			{
				ptrA[begin + i] = ptrSub[med];
				med++;
			}
			
		}
		
	}
	ptrSub = nullptr;
	delete[] ptrSub;
	return;	

}

void MegerSortBP::_descending(int total, int begin, int end)
{

	// begin--> To know in which index of the main array we want to start copying.
	// end----> To know in which index of the main array we want to end copying.
	// total--> Number of elements to be copied. 

	if (total < 2)
		return;

	ptrSub = new Point[total];
	for (size_t i = 0; i < total; i++)
		ptrSub[i] = ptrA[i + begin];

	if (total == 2)
	{
		if (ptrSub[0] >= ptrSub[1])
			return;
		else
		{
			ptrA[begin] = ptrSub[1];
			ptrA[begin + 1] = ptrSub[0];
			return;
		}

	}

	int start = 0;
	int med = (total & 1) ? ((total / 2) + 1) : total / 2;
	const int half = med;

	for (size_t i = 0; i < total; i++)
	{
		if (start < half && med <= end)
		{
			if (ptrSub[start] >= ptrSub[med])
			{
				ptrA[begin + i] = ptrSub[start];
				start++;
			}
			else
			{
				ptrA[begin + i] = ptrSub[med];
				med++;
			}
		}
		else
		{
			if (start < half)
			{
				ptrA[begin + i] = ptrSub[start];
				start++;
			}
			else
			{
				ptrA[begin + i] = ptrSub[med];
				med++;
			}

		}

	}
	ptrSub = nullptr;
	delete[] ptrSub;
	return;
}

