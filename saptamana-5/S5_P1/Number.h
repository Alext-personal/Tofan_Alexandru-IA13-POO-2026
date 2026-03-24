#pragma once
class Number
{
    char* value;
    int base;
public:
    Number(const char * value, int base); // where base is between 2 and 16
    Number(int value,int base);
    Number(const char* value);
    Number(int value);
    ~Number();
    // add operators and copy/move constructor
    Number(const Number& other);
    Number(Number&& other);
    Number& operator= (const Number& other);
    Number& operator=(Number&& other);
    Number& operator=(int value);
    Number& operator=(const char* value);
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    char operator [](int index);
    bool operator >(const Number& other);
    bool operator >=(const Number& other);
    bool operator <(const Number& other);
    bool operator <=(const Number& other);
    bool operator ==(const Number& other);
    Number& operator --();
    Number& operator --(int value);
    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};
