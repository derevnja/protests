#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <map>


using namespace std;

///frequency of K-length phrases
map<list<string>,int> ccount;
///another list of K-length phrases phrases
list<string> key;


/// table of frequency. Here we save:
/// list<string> - is phrase
/// map<string, int> - is map where save probability to see some "string" in text after "list<string>"
typedef list<string> phrase;
map<phrase,map<string, int> > Freq;

///probability table
map<phrase,map<string,double> > Prob;

const int PrecCoeff = 50;

///length of markov's chain
int K = 2;

unsigned int randomNum(unsigned int maxRangeVal)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, maxRangeVal);
    unsigned int val = dist(mt);

    return val;
}

void printFreqTable()
{
    //map<phrase,map<string, int> > Freq;
    for (auto it : Freq)
    {
        auto iii = it.second;
        for(auto iii: it.second)
        {
         if(iii.second > 1)
        //if(iii.second > 1)
        {
            cout << "phrase ---> ";
            for (auto i: it.first)
            {
                cout << i << " ";
            }
            cout << "  ";
            cout << "next word and frequency ";
            for(auto i: it.second)
            {
                cout << i.first << " " << i.second;
            }
            cout << endl;
        }
        }
    }
}

void analize(const char *filename)
{
    ifstream in;
    string s;
    in.open(filename);

    if(in)
    {
        ///read first K-words
        for(int i=0;i<K;i++)
        {
          in >> s; key.push_back(s);
        }
    }
    while(in >> s)
    {
        ccount[key]++;

        ///debug print
//        cout << "Frequency of " << K <<"-length phrase ";
//        for (auto it: key)
//        {
//            cout << it << " ";
//        }
//        cout << " --------> ";
//        cout << ccount[key] << endl;
        ///debug print

        Freq[key][s]++;
        key.push_back(s);
        key.pop_front();
    }
   // printFreqTable();
    for(auto iter_freq : Freq)
    {
        for(auto iter_phrase : iter_freq.second)
        {
            Prob[iter_freq.first][iter_phrase.first] = (iter_phrase.second + 1/2)/ double(ccount[iter_freq.first] + 500000);
            //cout << Prob[iter_freq.first][iter_phrase.first] << endl;
        }
    }
}

string getRandomWord(const map<string,double>& wordsTable)
{
    vector<string> words;
    for(auto iter : wordsTable)
    {
        fill_n(back_inserter(words),PrecCoeff*iter.second,iter.first);
        if (words.empty())
            cout << "Cannot generate new word!";
        return words[words.size() -1];
    }
}

void clearAllStructs()
{
    Freq.clear();
    Prob.clear();
    ccount.clear();
    key.clear();
}

void makePrintToFile()
{
    ///config output into file
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_CTYPE, "rus");
    ///init value for generated text
    int N = 10;
    ///make file reading much faster
    //std::ios_base::sync_with_stdio(false);

    ///config output into file
//    std::ofstream out("out.txt");
//    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    while(true)
    {
        cout << "enter key length" << endl;
        cin >> K;
        cout << "enter length of text to be generated" << endl;
        cin >> N;

        clearAllStructs();
        analize("../data/test.txt");

        ///generate randomly start element
        auto start = Prob.begin();
        advance(start, randomNum(Prob.size()));
        list<string> CurKey;
        CurKey.clear();
        CurKey= start->first;
        copy(CurKey.begin(),CurKey.end(),ostream_iterator<string>(cout, " "));
        cout << endl;

        for(unsigned int i=0;i<N;i++)
        {
            string temp = getRandomWord(Prob[CurKey]);
            CurKey.push_back(temp);;
            CurKey.pop_front();
            cout << temp << " ";
        }

        cout << endl<< endl<< endl;
    }

    return a.exec();
}
