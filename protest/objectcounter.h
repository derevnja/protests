#ifndef OBJECTCOUNTER
#define OBJECTCOUNTER

/*!
 *    class ResourseHolder(RSH) holds instanse count in itself
 */
#include <QString>
class ResourseHolder{
public:
    ///some class to throw exceptions
    class ExceptionGear{};
    static ResourseHolder* makeRSH();
    QString someResource;
private:
    ///copy assignment
    ResourseHolder& operator= (ResourseHolder&){}
    ///move assignment
    ResourseHolder& operator= (ResourseHolder&&){}
    ///copy constructor
    ResourseHolder(const ResourseHolder&):
          someResource(QString("Some value"))
    {}
    ///constructor
    ResourseHolder(){}
    ///value to keep count of created RSH objects
    static const unsigned int objectCounter = 0;
};

#endif // OBJECTCOUNTER

