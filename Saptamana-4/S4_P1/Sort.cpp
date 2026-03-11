#include "Sort.h"

#include <functional>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
Sort::Sort(int length, int minvalue, int maxvalue)
{
    this -> listSize = length;
    this -> list = new int[listSize];
    for (int i = 0; i < listSize; i++)
    {
        int new_value = minvalue + rand() % (maxvalue - minvalue + 1);
        this -> list[i] = new_value;
    }
}

Sort::Sort() : listSize(10), list(new int[10]{10,5,11,23,51,1,2,3,4,12})
{
}

Sort::Sort(int length, int* list)
{
    this -> listSize = length;
    this -> list = new int[listSize];
    for (int i = 0; i < listSize; i++)
        this -> list[i] = list[i];
}

Sort::Sort(int length, ...)
{
    this -> listSize = length;
    this -> list = new int[listSize];
    va_list args;
    va_start(args,length);
    for (int i = 0; i < length; i++)
        this -> list[i] = va_arg(args, int);
    va_end(args);
}

Sort::Sort(const char* list)
{
    char *temparray = new char[strlen(list) + 1];
    strcpy(temparray, list);
    this -> listSize = 0;
    int *templist = new int[strlen(list)]; // strlen(list) > listsize, asa ca fac un templist pe care il voi sterge dupa ce termin de folosit.
    char *p = strtok(temparray,",");
    while (p != NULL)
    {
        templist[this -> listSize++] = atoi(p);
        p = strtok(NULL,",");
    }
    this -> list = new int[this -> listSize]; //creez lista cu marimea sa normala
    for (int i = 0; i < this -> listSize; i++)
        this -> list[i] = templist[i];
    delete[] templist;
    delete[] temparray;
}

void Sort::InsertSort(bool ascendent)
{
    bool sortcondition;
    for (int i = 1; i < this -> listSize; ++i) {
        int key = this -> list[i];
        int j = i - 1;
        if (ascendent)
            sortcondition = this -> list[j] > key;
        else
            sortcondition = this -> list[j] < key;
        while (j >= 0 && sortcondition) {
            this -> list[j + 1] = this -> list[j];
            j = j - 1;
            if (ascendent)
                sortcondition = this -> list[j] > key;
            else
                sortcondition = this -> list[j] < key;
        }
        this -> list[j + 1] = key;
    }
}
static int Partition(bool ascendent,int *list, int low, int high)
{
    bool sortcondition;
    int pivot = list[high];
    int i = (low - 1);
    for (int k = low; k <= high - 1; k++)
    {
        if (ascendent)
            sortcondition = list[k] < pivot;
        else
            sortcondition = list[k] > pivot;
        if (sortcondition)
        {
            i++;
            std::swap(list[i], list[k]);
        }
    }
    std::swap(list[high], list[i + 1]);
    return i + 1;
}
void Sort::QuickSort(bool ascendent,int low,int high)
{
    if (low == high && low == -1)
        low = 0, high = this -> listSize - 1; // daca este prima intrare
    if(low < high)
    {
        int pi = Partition(ascendent,this -> list,low,high);
        QuickSort(ascendent,low,pi - 1);
        QuickSort(ascendent,pi + 1, high);
    }
}

void Sort::BubbleSort(bool ascendent)
{
    bool sortcondition;
    for (int i = 0; i < this -> listSize - 1; ++i)
        for (int j = i + 1; j < this -> listSize; ++j)
        {
            if (ascendent)
                sortcondition = this -> list[i] > this -> list[j];
            else
                sortcondition = this -> list[i] < this -> list[j];
            if (sortcondition)
            {
                int aux = this -> list[i];
                this -> list[i] = this -> list[j];
                this -> list[j] = aux;
            }
        }
}
void Sort::Print()
{
    for (int i = 0; i < this -> listSize; i++)
        printf("%d ", this -> list[i]);
    printf("\n");
}

int Sort::GetElementsCount()
{
    return this->listSize;
}

int Sort::GetElementFromIndex(int index)
{
    return this->list[index];
}







