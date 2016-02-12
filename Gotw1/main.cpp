#include <QCoreApplication>
#include <iostream>

using namespace std;

class Widget
{
private:
    int someValue;
public:
    Widget()
    {
        someValue++;
        cout << "Constructor"<< endl;
    }
    Widget(const Widget& _in)
    {
        cout << "Copy constructor" << endl;
    }
    ~Widget()
    {
        someValue--;
        cout << "Destructor" << endl;
    }
    int getValue()
    {
        return someValue;
    }
};

class SimpleC
{
public:
    int f;

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        ///simply calls constructor. If no constructor, w - is not initialized
        SimpleC w;
        cout << w.f << endl;
    }
    {
        Widget w(){

        }

        //w();
    }


    return a.exec();
}
