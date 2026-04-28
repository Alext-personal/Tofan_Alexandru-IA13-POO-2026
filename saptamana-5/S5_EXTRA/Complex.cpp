#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex operator+(const Complex& l, const Complex& r)
{
    Complex ret(l.real()+r.real(), l.imag()+r.imag());
    return ret;
}

Complex operator+(const Complex& l, double r)
{
    Complex ret(l.real()+r, l.imag());
    return ret;
}

Complex operator+(double l, const Complex& r)
{
    Complex ret(l+r.real(), r.imag());
    return ret;
}

Complex operator-(const Complex& obj)
{
    Complex ret(-obj.real(), -obj.imag());
    return ret;
}

bool operator==(const Complex& l, const Complex& r)
{
    return l.real() == r.real() && l.imag() == r.imag();
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    out<<complex.real()<<" "<<complex.imag()<<'i';
    return out;
}

