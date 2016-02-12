#include <fstream>
///read file
#include <iostream>
///read strings
#include <sstream>
///use std::vector
#include <vector>
/// for measuring execution time
#include <chrono>
/// reg expression use
#include <regex>

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
       //std::cout << "Copy construcnt here!";
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

size_t countFileWords(std::ifstream& in)
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

std::string matchWords(std::regex pieces_regex,std::ifstream& in)
{
    //read file to string
   // stringstream strStream;
   // strStream << in.rdbuf();//read the file
   // string str = strStream.str();//str holds the content of the file

    std::vector<std::string> someBigVector;
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
               // MyStr some(word);
                someBigVector.push_back(word);
            }
        }
    }


    // Extraction of several sub-matches
    std::smatch pieces_match;

    std::string fnames[] = {"foo.txt", "bar.txt", "baz.dat", "zoidberg"};
//    for (const auto &fname : fnames) {
//        if (std::regex_match(fname, pieces_match, pieces_regex)) {
//            std::cout << fname << '\n';
//            for (size_t i = 0; i < pieces_match.size(); ++i) {
//                std::ssub_match sub_match = pieces_match[i];
//                std::string piece = sub_match.str();
//                std::cout << "  submatch " << i << ": " << piece << '\n';
//            }
//        }
//    }
    for (const auto &fname : fnames) {
          std::cout << fname << ": " << std::regex_match(fname, pieces_regex) << '\n';
      }
    return std::string("");
}


std::string searchWords(std::ifstream& in)
{
    std::regex reg1("a");
    ///read words from input
    std::vector<std::string> someBigVector;
    someBigVector.reserve(1000000);
    std::string s;
    if(in.is_open())
    {
        while (in.good())
        {
            std::getline(in,s);
            //std::regex_search(s,reg1);
            std::sregex_iterator it(s.begin(), s.end(), reg1);
            std::sregex_iterator it_end;
            while(it != it_end) {
                 std::cout << it->str() << endl;
                 ++it;
            }

        }
        in.close();
    }
    ///end read words from input
    return std::string("");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
    std::ifstream in("../data/test.txt");
    //printFileWords(in);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    //cout << "words count " << countFileWords(in) << endl;
    //countFileWords(in);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << "duration " << duration << endl;

   // std::regex txt_regex("[a-z]+\\.txt");     
    cout << "searched strings " << searchWords(in);
    return a.exec();
}
