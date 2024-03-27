#include <iostream>
#include <fstream>
#include <vector>

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

int main()
{
    vector<double> num;
    string name;

    cout << "Enter the filename: ";
    getline(cin, name);
    
    num = readFile(name);

    cout << "The median of the data set is: " <<median(num)<< "." << endl;
    cout << "The mean of the data set is: " << mean(num) << "." << endl;
    //cout << "The mode of the data set is: " << mode(num) << "." << endl;
}

