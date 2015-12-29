#include "objectcounter.h"

ResourseHolder *ResourseHolder::makeRSH()
{
    if(objectCounter>1)
        throw ExceptionGear;
    else
        return new ResourseHolder;
}
