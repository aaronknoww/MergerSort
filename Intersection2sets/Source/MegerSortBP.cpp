#include "../Headers/Pch.h"
#include "../Headers/MegerSortBP.h"

using namespace std;

template<typename Dt>
MegerSortBP<Dt>::MegerSortBP()
{
	ptrMain  = nullptr;
	ptrLeft  = nullptr;
	ptrRight = nullptr; //To create sub array.
	_size = 0;

}
template<typename Dt>
void MegerSortBP<Dt>::ascendingOrder(Dt*& array, int elements)
{
	//array ------> Array to sort.
	//elements ---> Number of elements in the array.
	
	if (elements < 1)
		throw "Out of Range";

	if (elements == 1)
		return;

	ptrMain  = array;
	ptrRight = new Dt[(elements / 2) + 1];
	ptrLeft  = new Dt[(elements / 2) + 1];

	_size = 1;
	int contador = 0;
	int begin = 0;
	int end = 0;
	int central = 0;	
	do
	{ 
		
		_size += _size;
		for (int i = 0; i < elements/_size; i++)
		{
			contador += _size;
			begin = i * _size;
			end = begin + _size - 1;
			central = begin + _size / 2;
			lenLeft = _copySubArray(ptrLeft, begin, central-1);			
			lenRight = _copySubArray(ptrRight, central, (end<elements)?end:elements);
			_ascending(ptrLeft, ptrRight, begin, (end < elements) ? end : elements);
		}
		if (contador < elements && contador > 0)
		{
			
			lenLeft = _copySubArray(ptrLeft, contador - _size, contador - 1);
			lenRight = _copySubArray(ptrRight, contador, elements - 1); // probar con diferente valores
			_ascending(ptrLeft, ptrRight, contador - _size, elements - 1);
		}
		contador = 0;

	} while (_size < elements);
	
	
	delete ptrLeft;
	delete ptrRight;
	ptrLeft = nullptr;
	ptrRight = nullptr;

}
template<typename Dt>
void MegerSortBP<Dt>::descendingOrder(Dt*& array, int elements)
{
	if (elements < 1)
		throw "Out of Range";

	if (elements == 1)
		return;

	ptrMain = array;
	ptrRight = new Dt[(elements / 2) + 1];
	ptrLeft = new Dt[(elements / 2) + 1];

	_size = 1;
	int contador = 0;
	int begin = 0;
	int end = 0;
	int central = 0;
	do
	{

		_size += _size;
		for (int i = 0; i < elements / _size; i++)
		{
			contador += _size;
			begin = i * _size;
			end = begin + _size - 1;
			central = begin + _size / 2;
			lenLeft = _copySubArray(ptrLeft, begin, central - 1);
			lenRight = _copySubArray(ptrRight, central, (end < elements) ? end : elements);
			_descending(ptrLeft, ptrRight, begin, (end < elements) ? end : elements);
		}
		if (contador < elements && contador > 0)
		{			
			lenLeft = _copySubArray(ptrLeft, contador-_size, contador - 1);
			lenRight = _copySubArray(ptrRight, contador, elements - 1); // probar con diferente valores
			_descending(ptrLeft, ptrRight,contador-_size, elements - 1);
		}
		contador = 0;

	} while (_size < elements);
}
template<typename Dt>
void MegerSortBP<Dt>::_ascending(Dt*& left, Dt*& right, int begin, int end)
{
	// left---> Pointer to sub array, with elemnts to merge.
	// right--> Pointer to sub array, with elemnts to merge.
	// begin--> To know in which index of the main array we want to start modify.
	// end----> To know in which index of the main array we want to end modify.
	
	
	int total = end - begin + 1;
	int iLeft  = 0;
	int iRight = 0;
	
	for (int i = 0; i < total; i++)
	{
		if ((iLeft < lenLeft) && (iRight < lenRight))
		{
			if (ptrLeft[iLeft] <= ptrRight[iRight])
			{
				ptrMain[begin + i] = ptrLeft[iLeft];
				iLeft++;
			}
			else
			{
				ptrMain[begin + i] = ptrRight[iRight];
				iRight++;
			}
		}
		else if (iLeft >= lenLeft) // Ultima modificacion
		{
			ptrMain[begin + i] = ptrRight[iRight];
			iRight++;
		}
		else
		{
			ptrMain[begin + i] = ptrLeft[iLeft];
			iLeft++;
		}
	}

	return;	

}

template<typename Dt>
void MegerSortBP<Dt>::_descending(Dt*& left, Dt*& right, int begin, int end)
{
	// left---> Pointer to sub array, with elemnts to merge.
	// right--> Pointer to sub array, with elemnts to merge.
	// begin--> To know in which index of the main array we want to start modify.
	// end----> To know in which index of the main array we want to end modify.

	int total = end - begin + 1;
	int iLeft = 0;
	int iRight = 0;

	for (int i = 0; i < total; i++)
	{
		if ((iLeft < lenLeft) && (iRight < lenRight))
		{
			if (ptrLeft[iLeft] >= ptrRight[iRight])
			{
				ptrMain[begin + i] = ptrLeft[iLeft];
				iLeft++;
			}
			else
			{
				ptrMain[begin + i] = ptrRight[iRight];
				iRight++;
			}
		}
		else if (iLeft >= lenLeft) 
		{
			ptrMain[begin + i] = ptrRight[iRight];
			iRight++;
		}
		else
		{
			ptrMain[begin + i] = ptrLeft[iLeft];
			iLeft++;
		}
	}

	return;
	
}

template<typename Dt>
int MegerSortBP<Dt>::_copySubArray(Dt*& subArray, int begin, int end)
{
	int elements = end - begin;  
	int i = 0;
	for (; i <= elements; i++)
		subArray[i] = ptrMain[begin + i];
	return elements=i;
}

