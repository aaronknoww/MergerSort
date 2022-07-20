#include "../Headers/Pch.h"
#include "../Headers/MegerSortBP.h"

using namespace std;
MegerSortBP::MegerSortBP()
{
	ptrA = nullptr;
	ptrSub = nullptr; //To create sub array.
	_size = 0;
	_elment = 0;
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

	int elem = (elements & 1) ? elements + 1 : elements;

	
			//total=(_size * (i + 1) < elements)?_size:_size+1; this code is because elements if is an odd number,
			//											  you have to pass a lower total 
	
	int last = (elements & 1) ? 2 : 1; // This is because pair number or ao
	do
	{		
		for (size_t i = 0; i < elem / _size; i++)
			_ascending(_size, i * _size, i * _size + _size - last, (_size * (i + 1) <= elements) ? _size : _size - 1);
		_size += _size;

	} while (_size <= elem);


}

void MegerSortBP::descendingOrder(Point*& arr, int elemnts)
{

}

void MegerSortBP::exchange(Point a, Point b)
{

	aux = a;
	a = b;
	b = aux;
}

void MegerSortBP::_ascending(int size, int begin, int end, int total)
{
	// size---> To create a sub array to sort.
	// begin--> To know in which index of the main array we want to start copying.
	// end----> To know in which index of the main array we want to end copying.
	// total--> Number of elements to be copied. 
		
	if (total < 2)
		return;

	ptrSub = new Point[size];
	for (size_t i = 0; i < total; i++)
			ptrSub[i] = ptrA[i + begin];
	
	if (size == 2)
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


	int start = begin;
	int med = (total & 1) ? ((total / 2) + 1) : total / 2;
	const int half = med;
		
	for (size_t i = begin; i <total; i++)
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
			ptrA[begin + i] = (start < half) ? ptrSub[start] : ptrSub[med];
			start++;
			med++;
		}
		
	}
	ptrSub = nullptr;
	delete[] ptrSub;
	return;	

}

