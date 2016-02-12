#include <QCoreApplication>

#include "smart_pointer.h"
#include "testclass.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        SSPointer<Person> one_p = new Person("Ivan",35);


        //Person* one_p = new Person("Ivan",35);
        one_p->display();
    }

    {
        string s(NULL);
        s.length();
    }

    return a.exec();
}
