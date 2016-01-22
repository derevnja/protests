#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <chrono>


using namespace std;
using namespace std::chrono;

std::string get_file_contents(const char *filename)
{
  std::ifstream in(filename);
  if (in)
  {
    return(std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
  }
  throw(errno);
}

void searchSubString(std::string str,regex& reg)
{
    unsigned long counter = 0;
    //std::getline(in,s);
    std::sregex_iterator it(str.begin(), str.end(), reg);
    std::sregex_iterator it_end;
    // while(it != it_end) {
       //  cout << "line number " << counter << " " << it->str() << endl;
      //    ++it;
        // counter++;
     //}

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    cout << "general count " << distance(it,it_end) << endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
    cout << "duration of counts " <<duration;
}

std::string searchWords(std::ifstream& in,std::regex& reg1)
{
    unsigned long counter = 0;
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
              //  cout << "line number " << counter << " " << it->str() << endl;
                 ++it;
                counter++;
            }
        }
        in.close();
    }
    cout << "general count " << counter << endl;
    return std::string("");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //std::ifstream in("../data/test.txt");
    cout << "Enter words to be found" << endl;

    string wordToBeFound;
    cin >> wordToBeFound;

    regex reg(wordToBeFound);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    //searchWords(in,reg);
    std::string str;
    str = get_file_contents("../data/test.txt");
    searchSubString(str,reg);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
    cout << "duration in milisec's' " << duration << endl;

    return a.exec();
}
