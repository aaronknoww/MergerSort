// PROBLEM:

//Pregunta 1
//Intersection of two sets.Given two arrays a[] and b[], each containing n distinct 2D points in the plane,
//design a subquadratic algorithm to count the number of points that are contained both in array a[] and arrayb[]


#include "../Headers/Pch.h"
#include "../Headers/Point.h"
#include "../Headers/MegerSortBP.h"

using namespace std;


int countMatches(Point*& a, int elemA, Point*& b, int elemB);
int main()
{
    Point* a = new Point[4];
    Point* b = new Point[5];


    
    
    a[1] = Point(5, 5);
    a[2] = Point(3, 3);
    a[0] = Point(4, 4);
    a[3] = Point(5, 4);
    
    b[0] = Point(5, 4);
    b[1] = Point(3, 3);
    b[2] = Point(4, 4);
    b[3] = Point(5, 5);
    b[4] = Point(5, 5);

    
   
    
    cout << "\nmatches: " << countMatches(a, 4, b, 5);
    /*
    MegerSortBP as;
    as.ascendingOrder(a, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << "\n Punto a: "<< "x "<<a[i].getX()<<" y "<<a[i].getY();
    }*/

    system("pause > null");
    return 0;

}

int countMatches(Point*& a, int elemA, Point*& b, int elemB)
{
    MegerSortBP ascending;
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
