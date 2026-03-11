#include <cstdio>

#include "Sort.h"
int main(int argc, char* argv[])
{
    Sort a(10,1,100);
    Sort b;
    int temp[] = {9,12,3,4,1};
    Sort c(5,temp);
    Sort d(8,5,2,3,4,71,17,231,1000);
    Sort e("10,23,41,61,1,2,3,4,5");
    a.Print();
    b.Print();
    c.Print();
    d.Print();
    e.Print();
    printf("%s\n","======================================================");
    a.BubbleSort();
    a.Print();
    a.BubbleSort(true);
    a.Print();
    b.InsertSort();
    b.Print();
    b.InsertSort(true);
    b.Print();
    c.QuickSort();
    c.Print();
    c.QuickSort(true);
    c.Print();
    printf("%d\n",d.GetElementsCount());
    printf("%d\n",e.GetElementFromIndex(0));
}
