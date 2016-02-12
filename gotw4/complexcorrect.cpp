#include "complexcorrect.h"

ComplexCorrect::ComplexCorrect():
    real(0.0),
    imag(0.0)
{

}

ComplexCorrect::ComplexCorrect(double _real, double _imag):
    ///use {} instead of ()
    /// here the only bonus is check if type the same
    /// and we no type cast
    real{_real},
    imag{_imag}
{

}

ComplexCorrect &ComplexCorrect::operator+=(ComplexCorrect& other)
{
    real += other.real;
    imag += other.imag;
    return *this;
}

ComplexCorrect &ComplexCorrect::operator=(const ComplexCorrect &other)
{
    if(other == *this)
        return;

    this->real = other.real;
    this->imag = other.imag;

    return *this;
}

ostream &ComplexCorrect::print(ostream &stream)
{
    stream << "Real part = " << real << " Imagine part = " << imag;
    return stream;
}



ComplexCorrect operator+(ComplexCorrect val1, const ComplexCorrect &val2)
{
    val1 += val2;
    return val1;
}


ostream &operator<<(ostream &os, const ComplexCorrect &object)
{
    return object.print(os,);
}
