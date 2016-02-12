#ifndef ComplexIncorrect_H
#define ComplexIncorrect_H

/// Here is incorrect class description
/// I mentioned them and try to fix them in other class ComplexCorrect

#include <iostream>

using namespace std;

class ComplexIncorrect{
public:
    ComplexIncorrect( double r, double i = 0 )
    ///1. the better way is to use {} instread of ()
        : real(r), imag(i)
    { }
    ///2. a. it is better when + and += operators are non-members of class
    /// b. parameter should be passed by const&
    /// c. Instead of returning void, operator+ should return a complex
    ///
    void operator+ ( ComplexIncorrect other ) {
        real = real + other.real;
        imag = imag + other.imag;
    }

    ///3. operator<< should have a return type of ostream& and
    /// should return a reference to the stream
    void operator<<( ostream os ) {
        os << "(" << real << "," << imag << ")";
    }
    ///4. When you return *this, the return type should usually be a reference.
    ComplexIncorrect operator++() {
        ++real;
        return *this;
    }
    ///5. For consistency, always implement postincrement in terms of preincrement.
    ComplexIncorrect operator++( int ) {
        auto temp = *this;
        ++real;
        return temp;
    }

    // ... more functions that complement the above ...

private:
    double real, imag;
};

#endif // ComplexIncorrect_H
