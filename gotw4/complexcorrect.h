#ifndef COMPLEXCORRECT_H
#define COMPLEXCORRECT_H

#include <iostream>

using namespace std;

class ComplexCorrect
{
public:    
    ComplexCorrect();
    ComplexCorrect(double _real, double _imag);
    ComplexCorrect& operator+=(ComplexCorrect& other);
    ComplexCorrect& operator=(const ComplexCorrect& other);

    ostream& print(ostream& stream);

private:
    double real, imag;

};

/// c = a + b
ComplexCorrect operator+(ComplexCorrect val1, const ComplexCorrect& val2);

ostream& operator<<(ostream& os,const ComplexCorrect& object);


#endif // COMPLEXCORRECT_H
