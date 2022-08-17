// PROBLEMS:

//Problem 1
//Intersection of two sets.Given two arrays a[] and b[], each containing n distinct 2D points in the plane,
//design a subquadratic algorithm to count the number of points that are contained both in array a[] and arrayb[]


#include "../Headers/Pch.h"
#include "../Headers/Point.h"
#include "../Headers/MegerSortBP.h"
#include "../Source/MegerSortBP.cpp"

using namespace std;


int countMatches(Point*& a, int elemA, Point*& b, int elemB);
int main()
{
    //int cantidad = 9;
    //int* ipt = new int[cantidad];
    //int* ipt2 = new int[cantidad];

    //ipt[0] = 9;
    //ipt[1] = 8;
    //ipt[2] = 7;
    //ipt[3] = 6;
    //ipt[4] = 5;
    //ipt[5] = 5;
    //ipt[6] = 3;
    //ipt[7] = 2;
    //ipt[8] = 1;

    //ipt2[0] = 5;
    //ipt2[1] = 2;
    //ipt2[2] = 4;
    //ipt2[3] = 6;
    //ipt2[4] = 3;
    //ipt2[5] = 9;
    //ipt2[6] = 7;
    //ipt2[7] = 1;
    //ipt2[8] = 8;
    //
    //MegerSortBP<int> ord, ord2;
    ////ord.ascendingOrder(ipt, cantidad);
    //ord.descendingOrder(ipt, cantidad);
   
    //for (size_t i = 0; i < cantidad; i++)
    //{
    //    cout << "\n Punto a: " << "x " << ipt[i] << "  ipt2: ";// << ipt2[i];
    //}

    Point* a = new Point[4];
    Point* b = new Point[5];

    a[0] = Point(5, 5);
    a[1] = Point(3, 3);
    a[2] = Point(4, 4);
    a[3] = Point(5, 4);
    
    b[0] = Point(5, 4);
    b[1] = Point(3, 3);
    b[2] = Point(3, 3);
    b[3] = Point(5, 5);
    b[4] = Point(5, 5);

    
   
    
    cout << "\nmatches: " << countMatches(a, 4, b, 5)<<"\n";
    
    MegerSortBP<Point> as;
    as.descendingOrder(a, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << "\n Punto a: "<< "x "<<a[i].getX()<<" y "<<a[i].getY();
    }

    
    system("pause > null");
    return 0;

}

int countMatches(Point*& a, int elemA, Point*& b, int elemB)
{
    MegerSortBP<Point> ascending;
    ascending.ascendingOrder(a, elemA);
    ascending.ascendingOrder(b, elemB);
    if (a[elemA - 1] < b[0] || b[elemB - 1] < a[0])
        return 0;
    
    int match = 0;
    int index = 0;

    if (elemA <= elemB)
    {
        for (size_t i = 0; i < elemA; i++)
        {
            index = 0;
            while (index < elemB)
            {
                if (a[i].isEqual(b[index]))
                {
                    match++;
                    index++;
                    while (a[i].isEqual(b[index])) //In case there are more matches whith the same number.
                    {
                        match++;
                        index++;
                    }
                    break;
                }
                index++;
            }
        }

    }
    else
    {
        for (size_t i = 0; i < elemB; i++)
        {
            index = 0;
            while (index < elemA)
            {
                if (b[i].isEqual(a[index]))
                {
                    match++;
                    index++;
                    while (b[i].isEqual(a[index])) //In case there are more matches whith the same number.
                    {
                        match++;
                        index++;
                    }
                    break;
                }
                index++;
            }
        }

    }
    

    return match;
}
