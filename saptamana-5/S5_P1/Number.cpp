#include "Number.h"
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#define DEFAULTBASE 10
static char* ConvertIntToChar(int value)
{
    if (value == 0)
    {
        char *returnedValue = new char[2];
        returnedValue[0] = '0';
        returnedValue[1] = '\0';
        return returnedValue;
    }
    int digits = 0;
    int copy = value;
    while (copy)
    {
        copy/=10;
        digits++;
    }
    char *returnedValue = new char[digits+1];
    returnedValue[digits] = '\0';
    digits--;
    while (digits >= 0)
    {
        returnedValue[digits] = '0'+ (value%10);
        value/=10;
        digits--;
    }
    //printf("ConvertIntToChar ReturnedValue: %s\n",returnedValue);
    return returnedValue;
}
static char* ConvertFromBase10(const char* number,int base) // helper functions
{
    //printf("ConvertFromBase10 StartingValue: %s\n",number);
    if (base < 2 || base > 16)
        return nullptr;
    char newNumber[1001] = ""; //temp char
    int index = 0;
    int iNumber = atoi(number); // este baza 10 deci aici merge atoi
    if (iNumber == 0)
    {
        char* returnedNumber = new char[2];
        returnedNumber[0] = '0';
        returnedNumber[1] = '\0';
        return returnedNumber;
    }
    while (iNumber)
    {
        int digit = iNumber % base;
        if (digit <= 9)
            newNumber[index++] = '0' + digit;
        else
            newNumber[index++] = 'A' + (digit-10);
        iNumber /= base;
    }
    char *returnedNumber = new char[index+1];
    int j = 0;
    for (int i = index - 1; i >= 0; i--)
        returnedNumber[j++] = newNumber[i];
    returnedNumber[j] = '\0';
    //printf("ConvertFromBase10 ReturnedValue: %s\n",returnedNumber);
    return returnedNumber;
}
static char* ConvertToBase10(const char* number,int base) // helper functions
{
    if (base < 2 || base > 16)
        return nullptr;
    int newNumber = 0;
    int index = 0;
    int nLength = strlen(number);
    while (index < nLength)
    {
        int digit;
        if (number[nLength - 1 - index] >= 'A' && number[nLength - 1 - index] <= 'F')
            digit = number[nLength - 1 - index] - 'A' + 10;
        else
            digit = number[nLength - 1 - index] - '0';
        newNumber += digit*pow(base,index);
        index++;
    }
    return ConvertIntToChar(newNumber);
}
static char* ConvertBase(const char* number,int fromBase,int toBase)
{
    if (fromBase < 2 || fromBase > 16 || toBase < 2 || toBase > 16)
        return nullptr;
    if (fromBase == toBase)
    {
        char *newNumber = new char[strlen(number) + 1];
        strcpy(newNumber,number);
        return newNumber;
    }
    char *base10Intermediate = ConvertToBase10(number,fromBase);
    char *newNumber = ConvertFromBase10(base10Intermediate,toBase);
    delete[] base10Intermediate;
    return newNumber;
}

Number::Number(const char* value, int base)
{
    this -> base = base;
    this -> value = new char[strlen(value) + 1];
    strcpy(this -> value,value);
}

Number::Number(int value, int base)
{
    this -> base = base;
    this -> value = ConvertIntToChar(value);
}

Number::Number(const char* value)
{
    this -> base = DEFAULTBASE;
    this -> value = new char[strlen(value) + 1];
    strcpy(this -> value,value);
}

Number::Number(int value)
{
    this -> base = DEFAULTBASE;
    this -> value = ConvertIntToChar(value);
}

Number::~Number()
{
    delete[] this-> value;
}

Number::Number(const Number& other)
{
    this -> base = other.base;
    this -> value = new char[strlen(other.value) + 1];
    strcpy(this -> value,other.value);
}

Number::Number(Number&& other)
{
    this -> base = other.base;
    this -> value = other.value;
    other.value = nullptr;
}

Number& Number::operator=(const Number& other)
{
    delete[] this -> value;
    this -> base = other.base;
    this -> value = new char[strlen(other.value) + 1];
    strcpy(this -> value,other.value);
    return *this;
}

Number& Number::operator=(Number&& other)
{
    delete[] this-> value;
    this -> base = other.base;
    this -> value = other.value;
    other.value = nullptr;
    return *this;
}

Number& Number::operator=(int value)
{
    delete[] this -> value;
    char *sValue = ConvertIntToChar(value);
    if (this -> base != DEFAULTBASE)
    {
        char *newValue = ConvertBase(sValue,DEFAULTBASE,this->base);
        this -> value = newValue;
        delete[] sValue;
    }
    else
    {
        this -> value = sValue;
    }
    return *this;
}

Number& Number::operator=(const char* value)
{
    delete[] this -> value;
    char *sValue = new char[strlen(value) + 1];
    strcpy(sValue,value);
    if (this -> base != DEFAULTBASE)
    {
        char *newValue = ConvertBase(sValue,DEFAULTBASE,this->base);
        this -> value = newValue;
        delete[] sValue;
    }
    else
    {
        this -> value = sValue;
    }
    return *this;
}

Number& Number::operator+=(const Number& other)
{
    int newBase = std::max(this->base, other.base);
    char *thisBase10 = ConvertToBase10(this -> value,this->base);
    char *otherBase10 = ConvertToBase10(other.value,other.base);
    int iSum = atoi(thisBase10) + atoi(otherBase10);
    char *tempvalue = ConvertIntToChar(iSum);
    char *newValue = ConvertFromBase10(tempvalue,newBase);
    delete[] tempvalue;
    delete[] this -> value;
    delete[] thisBase10;
    delete[] otherBase10;
    this -> base = newBase;
    this -> value = newValue;
    return *this;
}
Number& Number::operator-=(const Number& other)
{
    int newBase = std::max(this->base, other.base);
    char *thisBase10 = ConvertToBase10(this -> value,this->base);
    char *otherBase10 = ConvertToBase10(other.value,other.base);
    int iSum = atoi(thisBase10) - atoi(otherBase10);
    if (iSum < 0)
        iSum = 0;
    char *tempvalue = ConvertIntToChar(iSum);
    char *newValue = ConvertFromBase10(tempvalue,newBase);
    delete[] tempvalue;
    delete[] this -> value;
    delete[] thisBase10;
    delete[] otherBase10;
    this -> base = newBase;
    this -> value = newValue;
    return *this;
}

char Number::operator[](int index)
{
    return this -> value[index];
}

bool Number::operator>(const Number& other)
{
    char *thisBase10 = ConvertToBase10(this -> value,this->base);
    char *otherBase10 = ConvertToBase10(other.value,other.base);
    int iThisBase10 = atoi(thisBase10);
    int iOtherBase10 = atoi(otherBase10);
    delete[] thisBase10;
    delete[] otherBase10;
    return iThisBase10 > iOtherBase10;
}

bool Number::operator>=(const Number& other)
{
    char *thisBase10 = ConvertToBase10(this -> value,this->base);
    char *otherBase10 = ConvertToBase10(other.value,other.base);
    int iThisBase10 = atoi(thisBase10);
    int iOtherBase10 = atoi(otherBase10);
    delete[] thisBase10;
    delete[] otherBase10;
    return iThisBase10 >= iOtherBase10;
}

bool Number::operator<(const Number& other)
{
    char *thisBase10 = ConvertToBase10(this -> value,this->base);
    char *otherBase10 = ConvertToBase10(other.value,other.base);
    int iThisBase10 = atoi(thisBase10);
    int iOtherBase10 = atoi(otherBase10);
    delete[] thisBase10;
    delete[] otherBase10;
    return iThisBase10 < iOtherBase10;
}

bool Number::operator<=(const Number& other)
{
    char *thisBase10 = ConvertToBase10(this -> value,this->base);
    char *otherBase10 = ConvertToBase10(other.value,other.base);
    int iThisBase10 = atoi(thisBase10);
    int iOtherBase10 = atoi(otherBase10);
    delete[] thisBase10;
    delete[] otherBase10;
    return iThisBase10 <= iOtherBase10;
}

bool Number::operator==(const Number& other)
{
    char *thisBase10 = ConvertToBase10(this -> value,this->base);
    char *otherBase10 = ConvertToBase10(other.value,other.base);
    int iThisBase10 = atoi(thisBase10);
    int iOtherBase10 = atoi(otherBase10);
    delete[] thisBase10;
    delete[] otherBase10;
    return iThisBase10 == iOtherBase10;
}

Number& Number::operator--()
{
    for(int i=0;i<this->GetDigitsCount()-1;i++)
        this -> value[i] = this -> value[i+1];
    this -> value[this->GetDigitsCount()-1] = NULL;
    return *this;
}

Number& Number::operator--(int value)
{
    this -> value[this->GetDigitsCount()-1] = NULL;
    return *this;
}

void Number::SwitchBase(int newBase)
{
    char *newValue = ConvertBase(this -> value,this -> base,newBase);
    this -> base = newBase;
    delete[] this -> value;
    this -> value = newValue;
}

void Number::Print()
{
    printf("Base : %d\nValue : %s\n",this -> base,this -> value);
}

int Number::GetDigitsCount()
{
    return strlen(this -> value);
}

int Number::GetBase()
{
    return this -> base;
}

Number operator+(const Number& n1, const Number& n2)
{
    Number n3(n1);
    return n3 += n2;
}
Number operator-(const Number& n1, const Number& n2)
{
    Number n3(n1);
    return n3 -= n2;
}

