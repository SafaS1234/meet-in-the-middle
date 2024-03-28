#include <iostream>
#include <fstream>
#include <vector>
//#include <cassert>
//#include "middle.hpp"

using namespace std;

vector <double> readFile(string name)
{
    vector <double> num;
    double fileNum;
    char comma;
    ifstream f;

    f.open(name);

    if (f.is_open())
    {
        while(f >> fileNum)
    {
        num.push_back(fileNum);
        f >> comma;
    }
    }
    
    else
    {
        cout << "Sorry, the file could not be opened." << endl;
    }

    f.close();

    return num;
}

double median(vector<double> num)
{
    double median;
    size_t size = num.size();

    if (size % 2 != 0) 
    {
        median = num[size/2];
    }

    else
    {
        median = (num[size/2-1]+num[size/2]) / 2.0;
    }

    return median;

}

double mean(vector<double> num)
{
    double mean, total;
    size_t size = num.size();

    for (size_t i = 0; i < size; i++)
    {
        total += num[i];
    }

    mean = total/size;

    return mean;

}

double mode(vector<double> num)
{
    double mode;
    size_t size = num.size();

    

    return mode;
}

int main()
{
    vector<double> num;
    string name;
    bool swapped;

    cout << "Enter the filename: ";
    getline(cin, name);
    
    num = readFile(name);
    
    for (size_t i = 0; i < num.size() -1; i++) {
        swapped = false;
        for (size_t j = 0; j < num.size() - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                swapped = true;
            }
        }
 
        if (swapped == false)
            break;
    }

    cout << "\nThe median of the data set is: " <<median(num)<< "." << endl;
    cout << "The mean of the data set is: " << mean(num) << "." << endl;
    //cout << "The mode of the data set is: " << mode(num) << "." << endl;

    //tests
    cout << "\n\nTests" << endl;
    cout << "\nWhile using data.txt" << endl;
    cout << "Expected ans = calculated ans" << endl;
    cout << "Median:   11 = " << median(num) << endl;
    cout << "Mean:     34 = " << mean(num) << endl;

    cout << "\nWhile using mix.txt" << endl;
    cout << "Expected ans = calculated ans" << endl;
    cout << "Median:   11 = " << median(num) << endl;
    cout << "Mean:     34 = " << mean(num) << endl;

    cout << "\nWhile using data2.txt" << endl;
    cout << "Expected ans = calculated ans" << endl;
    cout << "Median:   55 = " << median(num) << endl;
    cout << "Mean:     57 = " << mean(num) << endl;

    cout << "\nWhile using mix2.txt" << endl;
    cout << "Expected ans = calculated ans" << endl;
    cout << "Median:   55 = " << median(num) << endl;
    cout << "Mean:     57 = " << mean(num) << endl;

}

