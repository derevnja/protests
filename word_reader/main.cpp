#include <fstream>
///read file
#include <iostream>
///read strings
#include <sstream>
///use std::vector
#include <vector>
/// for measuring execution time
#include <chrono>

#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QString>

using namespace std;
using namespace std::chrono;

class MyStr
{
public:
    MyStr()
    {
       // std::cout << "Construcnt here!";
    }
    MyStr(string &ss): _s(ss)
    {
      //  std::cout << "Construcnt here!";
    }
    MyStr (const MyStr &T):_s(T._s)
    {
       // std::cout << "Copy construcnt here!";
    }

private:
    string _s;
};

void printFileWords(std::ifstream& in)
{
    std::string s;
    if(in.is_open())
    {
        while (in.good())
        {
            std::getline(in,s);
            std::istringstream iss(s);
            std::string word;
            while ( iss >> word )
            {
                word += "\n";
                std::cout << word;
            }
        }
    }
}

unsigned int countFileWords(std::ifstream& in)
{
    std::vector<MyStr> someBigVector;
    someBigVector.reserve(1000000);
    std::string s;
    if(in.is_open())
    {
        while (in.good())
        {
            std::getline(in,s);
            std::istringstream iss(s);
            std::string word;
            while ( iss >> word )
            {
                word += "\n";
                MyStr some(word);
                someBigVector.push_back(some);
            }
        }
    }
    return someBigVector.size();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
    std::ifstream in("../data/test.txt");
    //printFileWords(in);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    cout << countFileWords(in) << endl;
    //countFileWords(in);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration;



    return a.exec();
}
