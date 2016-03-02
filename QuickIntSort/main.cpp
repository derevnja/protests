#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

const char* FileName = "data.txt";

void quickIntSort(vector<int>& vec, int low_ind,int high_ind)
{
    if(high_ind < low_ind || high_ind == low_ind)
        return;
    int pivotIndex = low_ind;
    int storeIndex =  pivotIndex + 1;
    for(int i = pivotIndex + 1;i <= high_ind; i++)
    {
        if(vec[i] < vec[pivotIndex])
        {
            iter_swap(vec.begin() + i, vec.begin() + storeIndex);
            ++storeIndex;
        }
    }
    iter_swap(vec.begin() + pivotIndex, vec.begin() + storeIndex - 1);

    ///left side
    quickIntSort( vec, low_ind, storeIndex - 1 );
    ///right side
    quickIntSort( vec, storeIndex, high_ind  );
}

void generator(int size)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    std::ofstream fout(FileName);

    for (int i = 0; i<size; ++i)
        fout << dist(mt) << "\n";
    cout<<"done";
}

void readDataArray(vector<int>& _vec)
{
    ifstream iFin(FileName);
    string sValue;
    int iVal;
    while (getline(iFin, sValue))
    while (iFin >> sValue)
    {
        istringstream strStream(sValue);
        strStream >> iVal;
        _vec.push_back(iVal);
    }
    cout << "====================" << "\n";
    cout << "numbers count" << _vec.size()<<"\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> v_int;
    v_int.reserve(100);

//    cout << "Enter some numbers. Use space as delimiter \
//            and Enter as and of sequence" << endl;

//            int input;
//    while(cin>>input)
//        v_int.push_back(input);
    ///generate unsorted array of int
    generator(100);
    ///read array into vector
    readDataArray(v_int);

    quickIntSort(v_int,0,v_int.size()-1);
    std::copy(v_int.begin(), v_int.end(), std::ostream_iterator<int>(std::cout, " "));

    return a.exec();
}

