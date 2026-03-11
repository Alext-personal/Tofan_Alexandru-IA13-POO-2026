#pragma once
class Sort
{
    int *list;
    int listSize;
public:
    Sort(int length, int minvalue, int maxvalue);
    Sort();
    Sort(int length, int *list);
    Sort(int length,...);
    Sort(const char *list);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false,int low = -1,int high = -1); // am adaugat 2 parametrii ajutatori pentru quicksort-ul recursiv
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
