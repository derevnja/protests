#ifndef TESTCLASS
#define TESTCLASS

#include <iostream>

using namespace std;

class Person
{
    int age;
    char* pName;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(char* pName, int age): pName(pName), age(age)
        {
        }

        void display()
        {
            printf("Name = %s Age = %d \n", pName, age);
        }
        void shout()
        {
            printf("Ooooooooooooooooo");
        }
        ~Person()
        {
            cout <<"Destructor";
        }
};

#endif // TESTCLASS

